#include <iostream>
#include <cmath>
using namespace std;

bool Armstrong(int n, int num)
{
    int r;
    int temp = n;
    int armnum = 0;
    while (n > 0)
    {
        r = n % 10;
        armnum += pow(r, num);
        n = n / 10;
    }
    if (temp == armnum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;

    int num = 0, r;
    r = n;
    while (n > 0)
    {
        n = n / 10;
        num++;
    }
    cout << (Armstrong(r, num) == 1 ? "true" : "false");
    return 0;
}