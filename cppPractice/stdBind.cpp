#include <cstdio>
#include <functional>
using namespace std;

void foo(int x, int y, int z)
{
    printf("%d %d %d\n", x, y, z);
}

int main()
{
    // bind接受一个函数名foo，以及foo的3个参数
    auto f1 = std::bind(foo, 1, 2, 3);
    // CE：参数个数太少，需要3个参数
    // auto f2 = std::bind(foo, 1, 2);

    // print 1 2 3
    f1();
    // print 1 2 3
    f1(1, 2, 3);

    auto f3 = std::bind(foo, placeholders::_1, 2, 3);
    auto f4 = std::bind(foo, placeholders::_2, 2, 3);
    // print 10 2 3
    f3(10, 20, 30);
    // print 20 2 3
    f4(10, 20, 30);
    // CE：参数个数太少
    // f4(10);
    return 0;
}
