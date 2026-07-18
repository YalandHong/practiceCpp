#include <iostream>
#include <utility>

extern int counter;

struct Thing {
    int id;
    void get_id()
    {
        id = counter;
        counter++;
    }
    Thing()
    {
        get_id();
        std::cout << id << " 构造 (Default)\n";
    }
    Thing(const Thing& o)
    {
        get_id();
        std::cout << o.id << "->" << id << " 拷贝 (Copy)\n";
    }
    Thing(Thing&& o) noexcept
    {
        get_id();
        std::cout << o.id << "->" << id << " 移动 (Move)\n";
    }
    ~Thing()
    {
        std::cout << id << " 析构\n";
    }
};
