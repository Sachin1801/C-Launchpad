#include <bits/stdc++.h>
#define mod 10000003
using namespace std;

long modm(long a, long b)
{
    return ((a % mod) * (b % mod)) % mod;
}

bool checkCondn(long a[], long b, long p, long time, long t)
{
    long time_by_painter = 0;
    long p_consumed = 1;
    for (long i = 0; i < b; i++)
    {
        if ((time_by_painter + modm(a[i], t)) % mod <= time % mod)
        {
            time_by_painter += modm(a[i], t);
        }
        else
        {
            p_consumed++;
            time_by_painter = 0;
        }
    }

    if (time_by_painter == 0)
    {
        p_consumed--;
    }

    if (p_consumed <= p)
    {
        return true;
    }
    return false;
}

long check(long nop, long nob, long a[], long time)
{
    sort(a, a + nob);
    long s = a[nob - 1];
    long e = 0;
    long ans = -1;
    for (long i = 0; i < nob; i++)
    {
        e += a[i];
    }

    while (s <= e)
    {
        long mid = (s + e) / 2;
        if (checkCondn(a, nob, nop, mid, time))
        {
            e = mid - 1;
            ans = modm(mid, time);
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    long nop;
    long nob;
    long time;
    cin >> nop >> nob >> time;
    long a[nob];
    for (long i = 0; i < nob; i++)
    {
        cin >> a[i];
    }
    cout << check(nop, nob, a, time) << endl;
    return 0;
}