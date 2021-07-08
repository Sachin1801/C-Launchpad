#include <iostream>
using namespace std;

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    int ans = n * power(n, p - 1);
    return ans;
}

int main()
{
    //n is for number and p is for power
    int n, p;
    cin >> n >> p;
    cout << power(n, p) << endl;

    return 0;
}