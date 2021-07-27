#include <iostream>
using namespace std;

int friends(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    int cnt = 0;
    cnt = 1 * friends(n - 1) + friends(n - 1) * friends(n - 2);
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    cout << friends(n) << endl;
    return 0;
}