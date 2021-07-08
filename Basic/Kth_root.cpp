#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

long long check(ll n, ll k)
{
    ll s = 0;
    ll e = floor(pow(n, (1.0 / k))) + 1;
    ll ans = -1;
    while (s <= e)
    {
        ll mid = (s + e) / 2;
        if (pow(mid, k) > n)
        {
            e = mid - 1;
        }
        else if (pow(mid, k) <= n)
        {
            s = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    long long n;
    ll k;
    for (ll i = 0; i < t; i++)
    {
        cin >> n;
        cin >> k;
        cout << check(n, k) << endl;
    }
}