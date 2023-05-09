#include <stdio.h>

typedef struct {
    int x, y;
} foo;

int main()
{
    // foo a();
    // foo b();
    // a = b;

    // 大括号初始化是C++11引入的
    // G++的C++98抛警告，GCC直接报错
    foo hello { 1, 2 };
    printf("%d %d\n", hello.x, hello.y);
    return 0;
}
