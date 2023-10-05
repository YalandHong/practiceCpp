#include <iostream>
#include <memory>
using namespace std;

class foo {
  public:
    virtual void echo()
    {
        cout << "foo" << endl;
    }
    virtual ~foo() {};
};

class bar : public foo {
  public:
    virtual void echo() override
    {
        cout << "bar" << endl;
    }
    virtual ~bar() {};
};

void func1(foo& obj)
{
    obj.echo();
}
void func2(const shared_ptr<foo>& p)
{
    p->echo();
}

int main()
{
    foo a;
    bar b;
    func1(a);
    func1(b);

    cout << "--------" << endl;
    const foo* pf = &a;

    auto pa = make_shared<foo>();
    shared_ptr<foo> pab = make_shared<bar>();
    auto pb = make_shared<bar>();
    func2(pa);
    func2(pab);
    func2(pb);
    return 0;
}
