#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    float m, n;
    if (N % 2 == 0)
    {
        m = (N / 2);
        n = 1;
        cout << (m * m) - n << " " << (m * m) + 1;
    }
    if (N % 2 != 0)
    {
        m = ((N + 1) / 2);
        n = ((N - 1) / 2);
        cout << 2 * m * n << " " << (m * m) + (n * n);
    }
    return 0;
}