#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int L[n];
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    sort(L, L + n);
    int ans = 0;
    for (int i = 0; i < n - 1;)
    {
        if ((L[i + 1] - L[i]) <= d)
        {
            ans++;
            i += 2;
        }
        else
        {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}