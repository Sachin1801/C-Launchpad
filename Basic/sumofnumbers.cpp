#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1, sum = 0;

    while (i <= n)
    {
        sum = sum + i;
        i++;
    }

    cout << sum;

    return 0;
}
