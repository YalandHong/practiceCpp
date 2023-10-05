#include <cstddef>
#include <iostream>
using namespace std;

class foo {
    const size_t id;

  public:
    foo();
    size_t getVal() const
    {
        return id;
    }
};

class bar {
    const size_t id;

  public:
    bar();
    size_t getVal() const
    {
        return id;
    }
};

class ugh {
  public:
    ugh()
    {
        static bar bu;
        static foo fu;
        cout << "ugh: " << this << " has bu=" << bu.getVal()
             << " fu=" << fu.getVal()
             << " with addr bu=" << &bu << " and fu=" << &fu
             << endl;
    }
};

/**

在这个例子里，u0构造函数调用bu的构造函数，进而调用f0.getVal()
但是此时，f0还未执行构造，输出的id=0

这是有问题的，程序在没有执行对象的构造函数的情况下执行了它的成员函数

*/

static ugh u0;
static bar b0;
static foo f0;

// static bar b0;
// static ugh u0;

// bar::bar()
// {
//     cout << f0.val << endl;
//     cout << "bar: " << this << endl;
//     this->val = 456;
// }

foo::foo()
    : id((size_t)this)
{
    cout << "calling foo()" << endl;
    cout << b0.getVal() << endl;
    cout << "foo: " << this << endl;
}

bar::bar()
    : id((size_t)this)
{
    // static foo f1;
    cout << "calling bar()" << endl;
    cout << f0.getVal() << endl;
    cout << "bar: " << this << endl;
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
