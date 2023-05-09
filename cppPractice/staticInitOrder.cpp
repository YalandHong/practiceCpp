#include <iostream>
using namespace std;

class foo {
  public:
    foo()
    {
        cout << "foo: " << this << endl;
    }
};

foo f0;
static foo f1;

static void func()
{
    cout << "func start" << endl;
    static foo f2;
    cout << "func end" << endl;
}

int main()
{
    cout << "main start" << endl;
    static foo f3;
    func();
    cout << "main end" << endl;
    cout << &f0 << endl;
    cout << &f1 << endl;
    cout << &f3 << endl;
    return 0;
}
