#include <iostream>
using namespace std;

int f(int n, int k)
{
    //base case
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += f(n - i, k);
    }
    return ans;
}

int main()
{
    //max number of stepsthat can be taken at a time
    int n, k;
    cin >> n >> k;
    cout << f(n, k) << endl;
    return 0;
}