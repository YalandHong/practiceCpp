
typedef int line[10];
typedef struct {
    line data;
} foo;

line fun1(int x) { }
foo fun2()
{
    foo ret;
    return ret;
}

int main()
{
    line arr1, arr2;
    arr2 = arr1;
    return 0;
}
