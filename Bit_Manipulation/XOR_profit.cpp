#include <iostream>
using namespace std;

int main()
{
    int x;
    int y;
    cin >> x;
    cin >> y;
    int temp = 0;
    int ans = 0;
    while (x <= y)
    {
        temp = x ^ y;
        ans = max(ans, temp);
        x++;
    }
    cout << ans << endl;

    return 0;
}