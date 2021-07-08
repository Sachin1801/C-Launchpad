#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 0)
    {
        cout << "1" << endl;
        for (int i = 2; i <= n; i++)
        {
            cout << i - 1;
            for (int j = 1; j < i - 1; j++)
            {
                cout << "0";
            }
            cout << i - 1 << endl;
        }
    }
    return 0;
}