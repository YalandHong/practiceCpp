#include <iostream>
using namespace std;

class A {
  public:
    A()
    {
        cout << "default ctor " << this << endl;
    }
    A& operator=(const A& a)
    {
        cout << "copy assign = (const A& a) " << this
             << endl;
        return *this;
    }
    A(const A& a)
    {
        cout << "copy ctor " << this << endl;
    }
    // A(const A& a) = delete;
    // A(A&& a) = delete;
    // A(A&& a)
    // {
    //     cout << "move ctor " << this << endl;
    // }
    A(int x)
    {
        cout << "init " << this << " by x=" << x << endl;
    }
};

#define printPtr(ptr) cout << #ptr << ": " << ptr << endl

#define phase(n) cout << endl << n << endl;

int main(int argc, char const* argv[])
{
    // A a1;

    // A a2 = a1;

    // A a3(a1);

    A a4 = A();

    // a4 = a3;
    // A a5(A());

    A a6 = 10;

    // printPtr(&a1);
    // printPtr(&a2);
    // printPtr(&a3);
    printPtr(&a4);
    // printPtr(&a5);
    printPtr(&a6);
    return 0;
}
