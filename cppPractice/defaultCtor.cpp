/**
 * c++ - Conditions for automatic generation of default/copy/move ctor
and copy/move assignment operator? - Stack Overflow
https://stackoverflow.com/questions/4943958/conditions-for-automatic-generation-of-default-copy-move-ctor-and-copy-move-assi
 *
 *
 */
#include <iostream>
using namespace std;

class foo {
  public:
    // CTOR
    foo() { }
    foo(int x, int y = 35)
    {
        cout << "ctor " << x << "+" << y << endl;
    }

    // COPY
    foo(const foo&) {};
    foo& operator=(const foo&)
    {
        cout << "copy" << endl;
        return *this;
    }

    // MOVE
    // foo(foo&&) {};
    // foo& operator=(foo&&)
    // {
    //     cout << "move" << endl;
    //     return *this;
    // }
    // foo(foo&&) = delete;
    // foo(const foo&) = delete;
};

int main()
{
    foo noarg;
    foo noarg2;
    // foo* obj = new foo(2, 3);
    // foo mv = foo(1, 2);
    // foo cp(mv);
    // foo mv(foo(1, 2));
    // mv = *obj;
    // noarg = noarg2;
    noarg2 = foo();
    noarg2 = noarg;

    foo n = { 33, 4 };

    // foo cp(noarg);
    return 0;
}
