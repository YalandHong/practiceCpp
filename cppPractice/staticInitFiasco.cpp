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

class ugh {
  public:
    ugh();
};

/**

在这个例子里，u0构造函数调用f0.getVal()
但是此时，f0还未执行构造，输出的id=0

这是有问题的，程序在没有执行对象的构造函数的情况下执行了它的成员函数

*/

static ugh u0;
static foo f0;

foo::foo()
    : id((size_t)this)
{
    cout << "calling foo()" << endl;
    cout << "foo: " << this << endl;
}

ugh::ugh()
{
    cout << "ugh: " << this << " has fu=" << f0.getVal()
         << " and f0=" << &f0 << endl;
}

#define printPtr(ptr) cout << #ptr << ": " << ptr << endl

int main()
{
    cout << "main start" << endl;
    printPtr(&f0);
    cout << "main end" << endl;
    return 0;
}
