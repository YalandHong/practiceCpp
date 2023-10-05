#include <iostream>
using namespace std;

class A {
  public:
    virtual void foo()
    {
        cout << "A::foo" << endl;
    }
    void bar()
    {
        foo();
    }
};
class B : public A {
  public:
    virtual void foo()
    {
        cout << "B::foo" << endl;
    }
};

int main()
{
    A a;
    B b;
    A* p = new B;
    a.bar();
    b.bar();
    p->bar();

    return 0;
}
