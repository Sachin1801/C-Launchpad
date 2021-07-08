#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
    }
    else if (n == 2)
    {
        cout << "1" << endl;
        cout << "2\t2" << endl;
    }
    else
    {
        cout << "1" << endl;
        cout << "2\t2" << endl;
        for (int i = 3; i <= n; i++)
        {
            cout << i << '\t';
            for (int j = 1; j < i - 1; j++)
            {
                cout << "0\t";
            }
            cout << i << endl;
        }
    }
    return 0;
}