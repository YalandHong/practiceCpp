#include <iostream>
using namespace std;

class foo {
  public:
    int func(int x, int y)
    {
        cout << x + y << endl;
        return x + y;
    }
};

class bar1 : public foo { };
class bar2 : public foo { };

class now : public bar1, public bar2 {
  public:
    int call(int x, int y)
    {
        // return func(x, y);
        // return foo::func(x,y);
        return bar1::func(x, y);
    }
    void func(int x, int y)
    {
        cout << x * y << endl;
    }
};

int main()
{
    now obj;
    obj.call(1, 2);
    // cout << obj.func(3, 4) << endl;
    obj.func(3, 4);
    obj.bar1::func(7, 9);
    return 0;
}
