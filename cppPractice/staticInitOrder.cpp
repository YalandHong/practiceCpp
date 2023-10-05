#include <iostream>
using namespace std;

#define printPtr(ptr) cout << #ptr << ": " << ptr << endl

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
    printPtr(&f0);
    printPtr(&f1);
    printPtr(&f3);
    return 0;
}
