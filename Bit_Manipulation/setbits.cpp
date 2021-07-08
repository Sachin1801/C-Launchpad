#include <iostream>

using namespace std;

//First method
/*int countbits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += (n & 1);
        n = n >> 1;
    }
    return ans;
}
*/

//Second Method
int countbitsfast(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int n;
        cin >> n;
        //cout << countbits(n) << endl;
        cout << countbitsfast(n) << endl;
        //inbuilt popcount funtion
        //cout << __builtin_popcount(n) << endl;
    }
}