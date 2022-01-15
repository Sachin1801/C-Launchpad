#include <iostream>
using namespace std;

int checksubsetsum(int a[], int size, int p, int sum, int eis)
{
    //base case
    if (p == size)
    {
        if (sum == 0 and eis >= 1)
        {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    //recursive case
    //including the next number in the subset
    ans += checksubsetsum(a, size, p + 1, sum + a[p], eis + 1);
    //excluding the next number in the subset
    ans += checksubsetsum(a, size, p + 1, sum, eis);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (checksubsetsum(a, n, 0, 0, 0) > 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}