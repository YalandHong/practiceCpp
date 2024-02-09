#include <iostream>
#include <memory>
using namespace std;

void func(const shared_ptr<int>& p)
{
    cout << *p << endl;
}

// void func2(shared_ptr<int>& const p)
// {
//     cout << *p << endl;
// }

int main()
{
    shared_ptr<int> p1 = make_shared<int>();
    shared_ptr<int> const p2 = make_shared<int>();
    return 0;
}
