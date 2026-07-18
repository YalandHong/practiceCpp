#include "thing.hpp"

// 第三级：最终产生对象的函数
Thing producer()
{
    Thing t;
    t.id = 100;
    std::cout << "  Producer 修改后的地址: " << &t
              << " | id: " << t.id << std::endl;
    return t;
}

// 第二级：中间处理层
Thing layer1()
{
    Thing t1 = producer();
    t1.id += 50; // 在中间层继续修改
    std::cout << "  Layer1 修改后的地址:   " << &t1
              << " | id: " << t1.id << std::endl;
    return t1;
}

// 第一级：顶级调用者
int main()
{
    std::cout << "--- 开始调用链 ---" << std::endl;

    Thing final_obj = layer1();

    std::cout << "--- 调用链结束 ---" << std::endl;
    std::cout << "  Main 最终拿到的地址:   " << &final_obj
              << " | id: " << final_obj.id << std::endl;

    return 0;
}
