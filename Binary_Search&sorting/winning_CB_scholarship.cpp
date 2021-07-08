#include <iostream>
using namespace std;

int Scholarships(long n, long m, long x, long y)
{
    long s = 0;
    long e = n;
    long ans;
    while (s <= e)
    {
        long mid = (s + e) / 2;
        if ((mid * x) <= (m + (n - mid) * y))
        {
            s = mid + 1;
            ans = mid;
        }
        else if ((mid * x) > (m + (n - mid) * y))
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long N, M, X, Y;
    //N=number of students
    //M=number of coupons available
    //X=number of coupons required of each student to get the scholarship
    //Y=number of coupons that can be borrowed
    cin >> N >> M >> X >> Y;
    cout << Scholarships(N, M, X, Y) << endl;
    return 0;
}