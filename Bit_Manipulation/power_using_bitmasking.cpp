#include <iostream>
using namespace std;

int powerusingbitmasking(int a, int n)
{
    int ans = 1;
    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit)
        {
            ans *= a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << powerusingbitmasking(a, n) << endl;
    return 0;
}