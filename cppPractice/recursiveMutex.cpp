#include <iostream>
#include <mutex>
using namespace std;

struct MyGuard {
    MyGuard(recursive_mutex& m)
        : lock(m)
    {
        lock.lock();
        cout << "guard lock" << endl;
    }
    ~MyGuard()
    {
        cout << "guard unlock" << endl;
        lock.unlock();
    }

    recursive_mutex& lock;
};

void f1(recursive_mutex& m)
{
    MyGuard guard(m);
    cout << "f1 run" << endl;
}

void f2(recursive_mutex& m)
{
    MyGuard guard(m);
    f1(m);
    cout << "f2 run" << endl;
}

int main()
{
    recursive_mutex m;
    f2(m);
    return 0;
}
