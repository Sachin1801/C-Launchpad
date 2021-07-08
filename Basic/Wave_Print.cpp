#include <iostream>
using namespace std;

int main()
{
    int a[1000][1000] = {0};
    int m, n;
    cin >> m >> n;
    int val = 1;
    for (int i = 0; i <= m - 1; i++)
    {

        for (int j = 0; j <= n - 1; j++)
        {
            a[i][j] = val;
            val++;
        }
    }
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j <= m - 1; j++)
            {
                cout << a[j][i] << " ";
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << a[j][i] << " ";
            }
        }
    }
    return 0;
}

