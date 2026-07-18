#include "thing.hpp"

Thing return_param(Thing t)
{
    return t; // 参数不满足 Elision，但满足移动
}

Thing nrvo_failure(bool flag)
{
    Thing a, b;
    if (flag)
        return a; // 多个出口导致 NRVO 极难发生
    return b;
}

void test_move_from_param()
{
    std::cout << "--- Move from Param ---\n";
    Thing t1 = return_param(
        Thing()); // 1构造(传参消除) + 1移动(返回)
}
void test_move_from_nrvo_failure()
{
    std::cout << "--- Move from NRVO Failure ---\n";
    Thing t2 = nrvo_failure(true); // 2构造 + 1移动
}

int main()
{
    test_move_from_param();
    test_move_from_nrvo_failure();
    return 0;
}
