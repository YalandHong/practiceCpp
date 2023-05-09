#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class foo {
    int val;

  public:
    // foo(const int* p)
    // {
    //     cout << this << " from p=" << p << endl;
    //     val = *p;
    // }
    explicit foo(const int* p)
    {
        cout << this << " from p=" << p << endl;
        val = *p;
    }
    // foo(const foo& obj) = delete;
    // foo(const foo& obj)
    // {
    //     cout << this << " from obj=" << &obj << endl;
    //     val = obj.val;
    // }
};

int main()
{
    foo tmp = foo(new int); // explicit
    // foo obj = new int; // implicit

    return 0;
}
