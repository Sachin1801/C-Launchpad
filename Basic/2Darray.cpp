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

    for (int i = 0; i <= m - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
