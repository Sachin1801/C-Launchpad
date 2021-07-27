#include <iostream>
using namespace std;

void placetiles(int n)
{
    if (n <= 3)
    {
        return 1;
    }
    int cnt = 0;
    if (n > 3)
    {
        cnt = cnt + placetiles(n - 1);
        cnt = cnt + placetiles(n - 4);
    }
    return cnt;
}

int main()
{
    int len;
    cin >> len;
    cout << placetiles(len) << endl;

    return 0;
}