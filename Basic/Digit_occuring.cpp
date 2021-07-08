#include <iostream>
using namespace std;

int main()
{
    int N, n;
    int num = 0;
    int r;
    cin >> N >> n;
    while (N > 0)
    {
        r = N % 10;
        if (r == n)
        {
            num++;
        }
        N = N / 10;
    }
    cout << num;
    return 0;
}