#include "thing.hpp"

Thing make_thing()
{
    return Thing(); // 临时对象
}

void take_thing(Thing t) { }

void test_rvo()
{
    std::cout << "--- RVO ---\n";
    Thing t
        = make_thing(); // 结果：仅 1 次构造，无拷贝无移动
}
void test_param_elision()
{
    std::cout << "--- Param Elision ---\n";
    take_thing(Thing()); // 结果：仅 1 次构造，无拷贝无移动
}

int main()
{
    test_rvo();
    test_param_elision();
    return 0;
}
