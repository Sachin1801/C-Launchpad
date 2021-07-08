#include <iostream>
using namespace std;

int main()
{
    int a[100][100];
    int r, c;
    int i, j, i1, j1;
    cin >> r >> c;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int tlr, tlc, brr, brc;

    for (tlr = 0; tlr < r - 1; tlr++)
    {
        for (tlc = 0; tlc < c - 1; tlc++)
        {
            for (brr = tlr + 1; brr < r - 1; brr++)
            {
                for (brc = tlc + 1; brc < c - 1; brc++)
                {
                    int sum = 0;
                    for (i1 = tlr; i1 <= brr; i1++)
                    {
                        for (j1 = tlc; j1 < brc; j1++)
                        {
                            sum += a[i1][j1];
                        }
                        cout << sum << endl;
                    }
                }
            }
        }
    }
    return 0;
}