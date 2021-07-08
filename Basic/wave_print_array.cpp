#include <iostream>
using namespace std;

int main()
{
    int a[10][10];
    int m, n; //m for rows and n for columns
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int c = 0;
    while (c < n)
    {

        if (c % 2 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << a[i][c] << ",";
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << a[i][c] << ",";
            }
        }

        c++;
    }

    cout << "END";
    return 0;
}