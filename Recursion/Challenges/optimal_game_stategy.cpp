#include <bits/stdc++.h>
using namespace std;

int solve(int *a, int i, int j)
{

    if (i == j)
    {
        return a[i];
    }
    else if (i + 1 == j)
    {
        return max(a[i], a[i + 1]);
    }

    return max(a[i] + min(solve(a, i + 2, j), solve(a, i + 1, j - 1)), a[j] + min(solve(a, i, j - 2), solve(a, i + 1, j - 1)));
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

    cout << solve(a, 0, n - 1) << endl;
}