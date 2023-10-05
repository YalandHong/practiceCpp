#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class foo {
  public:
    foo() = delete;
    foo(int x)
    {
        printf("%d: %d\n", id, x);
        ++id;
    }

  private:
    static int id;
};

int foo::id = 0;

int main()
{
    // ok
    printf("1\n");
    vector<foo> a;

    // CE
    // printf("2\n");
    // vector<foo> b(10);

    // ok
    printf("3\n");
    vector<foo> c;
    c.push_back(foo(123));

    // ok
    printf("4\n");
    vector<foo> d;
    d.reserve(100);

    // ok
    printf("5\n");
    vector<foo> e { foo(10), foo(20) };

    // ok
    printf("6\n");
    vector<foo> f;
    // f.resize(10); // CE
    f.resize(10, foo(3));
    return 0;
}
