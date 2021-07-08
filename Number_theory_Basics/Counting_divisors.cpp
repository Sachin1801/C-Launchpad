#include <iostream>
using namespace std;

int main()
{
    int N = 1000000;
    int p[1000000] = {0};
    vector<int> primes = primesieve(p, 10000);
    int t;
    cin >> t;
    while (t--)
    {
        int no;
        cin >> no;
        int divs = no_of_divisors(no, primes);
        cout << divs << endl;
    }
    return 0;
}