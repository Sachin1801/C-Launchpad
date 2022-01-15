#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (a[i] < a[0])
            {
                cout << a[0] << " ";
                break;
            }
            else
            {
                cout << -1 << " ";
                break;
            }
        }
        if (n == 1 or n == 0)
        {
            cout << -1 << " ";
        }
        if (a[i] + 1 <= a[i + 1])
        {
            cout << a[i + 1] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    return 0;
}