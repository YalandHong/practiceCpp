
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void checkString(const string& input, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << input[i] << "-" << endl;
        // cout << input.at(i) << "-" << endl;
    }
}
void checkVec(const vector<int>& input, int n)
{
    for (int i = 0; i < n; ++i) {
        cout << input[i] << "-" << endl;
        // cout << input.at(i) << "-" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    {
        string input(5, 'x');
        checkString(input, n);
    }

    {
        vector<int> input(5, 1);
        // crash after commenting this line
        // input.reserve(100);
        checkVec(input, n);
    }
    return 0;
}
