#include "thing.hpp"

Thing make_named_thing()
{
    Thing t;
    return t; // 局部变量
}

Thing return_const()
{
    const Thing ct;
    return ct;
}

Thing change_member()
{
    Thing t;
    t.id = 1456;
    std::cout << "Change " << &t << " to " << t.id
              << std::endl;
    return t;
}

void test_named_thing()
{
    std::cout << "--- NRVO ---\n";
    Thing t
        = make_named_thing(); // 结果：在编译器能够实现的情况下，常仅
                              // 1 次构造
}
void test_copy_const()
{
    std::cout << "--- Copy from Const ---\n";
    Thing t2
        = return_const(); // 在编译器能够实现的情况下，1构造
}
void test_change_member()
{
    std::cout << "--- NRVO with member changing ---\n";
    Thing t3
        = change_member(); // 直接构造，对id的修改直接在caller空间进行
}

int main()
{
    test_named_thing();
    test_copy_const();
    test_change_member();
    return 0;
}
