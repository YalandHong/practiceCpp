#include <iostream>
using namespace std;

void func(char arr[128])
{
    cout << sizeof(arr) << endl;
}

int main()
{
    char arr[128];
    cout << sizeof(arr) << endl;
    func(arr);

    char* p = &*arr;
    cout << "p=" << (void*)p << " arr=" << (void*)arr
         << endl;

    int a[10];

    int* p1 = a; // OK
    int(*p2)[10]
        = a; // cannot convert ‘int*’ to ‘int (*)[10]’
    int(*p3)[10] = &a; // OK
    int(*p4)[20] = &a;
    return 0;
}
