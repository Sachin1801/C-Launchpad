#include <iostream>
#include <cstring> //header file for memset function
using namespace std;
#define ll long

ll a[1000005], freq[1000005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(freq, 0, sizeof(freq));
        freq[0] = 1;
        //read the input
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;
            freq[sum]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll m = freq[i];
            ans = ans + (((m) * (m - 1)) / 2);
        }
        cout << ans << endl;
    }
}