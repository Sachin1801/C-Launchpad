#include <iostream>
using namespace std;

int setbits(int n)
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
    int q;
    cin >> q;
    int a, b;

    for (int i = 0; i < q; i++)
    {
        int fans = 0;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            //int temp= setbits(j);
            fans = fans + setbits(j);
        }
        cout << fans << endl;
    }
    return 0;
}