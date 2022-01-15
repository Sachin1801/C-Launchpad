#include <iostream>
using namespace std;

void sumofarrays(int a[], int b[], int asize, int bsize)
{
    int sum[Max];
    int Max = max(asize, bsize);
    int carryover;
    int tempsum;
    while (Max--)
    {
        while (asize-- and bsize--)
        {
            if (asize == 0)
            {
                tempsum = b[bsize];
            }
            elseif(bisze == 0)
            {
                tempsum = a[asize];
            }
            else
            {
                tempsum = a[asize] + b[bsize];
                carryover = tempsum % 10;
                tempsum = tempsum / 10;
                sum[Max] = tempsum;
                if (asize == 0)
                {
                    b[bsize - 1] += carryover;
                }
                else
                {
                    a[asize - 1] += carryover;
                }
            }
        }
    }
    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << ", ";
    }
    cout << "END";
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sumofarrays(a, b, n, m);
    return 0;
}