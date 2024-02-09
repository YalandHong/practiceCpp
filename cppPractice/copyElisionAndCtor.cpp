/**

这段代码探究不同场景下使用哪种ctor
以及是否存在copy elision

*/

#include <iostream>
#include <type_traits>
using namespace std;

class Person {
  public:
    Person()
    {
        cout << "Default" << endl;
    }
    Person(const Person& p)
    {
        age = p.age;
        name = p.name;
        cout << "Copy" << endl;
    }
    Person(Person&& p)
    {
        age = p.age;
        swap(name, p.name);
        cout << "Move" << endl;
    }

    Person& operator=(const Person& p)
    {
        cout << "operator =" << endl;
        age = p.age;
        name = p.name;
        return *this;
    }

    int age;
    string name;
};

void f(Person p)
{
    return;
}

Person f1()
{
    Person p;
    p.age = 100;
    p.name = "foo1";
    return p;
}

#define PrintCase(x) cout << endl << #x "----" << endl

int main()
{
    PrintCase(0);
    Person p;

    PrintCase(1);
    Person p1 = p;

    PrintCase(2);
    Person p2;
    p2 = p;

    PrintCase(3);
    f(p2);

    /**
    f1调用了一次默认构造，再调用一次等号赋值给p2
    */
    PrintCase(4);
    p2 = f1();

    /**
    出现copy elision，这里只调用了一次默认构造
    */
    PrintCase(5);
    Person p3 = f1();

    return 0;
}
