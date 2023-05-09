#include <iostream>
using namespace std;

class foo {
  public:
    foo();
    static int val;
};

class bar {
  public:
    bar();
    static int val;
};

int foo::val;
int bar::val;

static bar b0;
static foo f0;
// static bar b0;

// bar::bar()
// {
//     cout << f0.val << endl;
//     cout << "bar: " << this << endl;
//     this->val = 456;
// }

foo::foo()
{
    cout << b0.val << endl;
    cout << "foo: " << this << endl;
    this->val = 123;
}

bar::bar()
{
    // static foo f1;
    cout << f0.val << endl;
    cout << "bar: " << this << endl;
    this->val = 456;
}

#define printPtr(ptr) cout << #ptr << ": " << ptr << endl

int main()
{
    cout << "main start" << endl;
    printPtr(&f0);
    printPtr(&b0);
    cout << "main end" << endl;
    return 0;
}
