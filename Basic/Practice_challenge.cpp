#include <iostream>
using namespace std;

int main()
{
    int N1, N2;
    int ans = 0;
    int j = 1;
    int i = 1;
    cin >> N1 >> N2;

    while (i <= N1)
    {
        ans = (3 * j) + 2;
        if (ans % N2 != 0)
        {
            cout << ans << endl;
            i++;
        }
        j++;
    }
    return 0;
}