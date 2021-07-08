//Problem on hacker blocks under bitmasking
#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    while (t--)
    {
        ll n;
        cin >> n;
        ll subsets = (1 << 8) - 1; // 2^8 possible subsets as prime numbers less than 20 is 8 as written above in array primes[]
        ll ans = 0;
        for (ll i = 0; i <= subsets; i++)
        {
            ll denom = 1ll;
            ll setbits = __builtin_popcount(i);
            for (ll j = 0; j <= 7; j++)
            {
                if (i & (1 << j)) // (1<<j)is the mask , we are doing this to check and which place the setbit is 1
                {
                    denom = denom * primes[j]; //multiplying it with the place where the bit is 1 and multiplying it with the prime number of the according place in the array
                }
            }
            if (setbits & 1) //checking if the number of setbits is odd
            {
                ans += n / denom;
            }
            else
            { // if not odd then it is even
                ans -= n / denom;
            }
        }
        cout << ans << endl;
    }
    return 0;
}