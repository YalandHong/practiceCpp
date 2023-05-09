#include <iostream>
using namespace std;

class pure {
  public:
    virtual int func(int x, int y) = 0;
};

class foo : public pure {
  public:
    int func(int x, int y) = delete;
};

int main()
{
    foo* obj = new foo;
    cout << obj->func(1, 2) << endl;
    return 0;
}
