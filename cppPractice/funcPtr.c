#include <stdio.h>
#include <stdlib.h>

void add(int a, int b)
{
    char* ok = "ok";
    printf("%s a + b = %d\n", ok, a + b);
}

void (*pointer)(void) = add;

int main()
{
    add(5, 5);
    return 0;
}
