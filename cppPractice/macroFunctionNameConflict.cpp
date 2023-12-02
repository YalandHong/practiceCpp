
// #define floor(x, y) ((x) / (y))

// #define min(x, y) ((x) < (y) ? (x) : (y))

#include <iostream>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int a, b;
    cin >> a >> b;
    int c = std::min(a, b);
    cout << c << endl;
    return 0;
}
