#include <iostream>
using namespace std;

int Squareroot(int n)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if ((mid * mid) > n)
        {
            e = mid - 1;
        }
        else if ((mid * mid) == n)
        {
            return mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    cout << Squareroot(n) << endl;
}