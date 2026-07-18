#include "thing.hpp"

Thing global_t;

Thing return_global()
{
    return global_t; // 全局变量不能移动
}

void test_copy_global()
{
    std::cout << "--- Copy from Global ---\n";
    Thing t1 = return_global(); // 1拷贝
}
int main()
{
    test_copy_global();
    return 0;
}
