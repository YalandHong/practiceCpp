#include <iostream>
using namespace std;

class pure {
  public:
    virtual int func(int x, int y) = 0;
    // 纯虚函数如果有函数体则必须要分离，不能写到和声明一起
    // { return x+y; }
};

int pure::func(int x, int y)
{
    return x + y;
}

class foo {
  public:
    // static member cannot be virtual
    static int func(int x, int y)
    {
        return x + y;
    }
    static int div(int x, int y)
    {
        return x / y;
    }
    // https://stackoverflow.com/questions/733737/are-inline-virtual-functions-really-a-non-sense
    virtual inline int multi(int x, int y)
    {
        return x * y;
    }
};

int main()
{
    foo* obj = new foo;
    cout << obj->func(1, 2) << endl;
    cout << foo::div(3, 4) << endl;
    cout << obj->multi(14, 15) << endl;
    return 0;
}
