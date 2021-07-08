#include <iostream>
using namespace std;

int main()
{
    int a[1000];
    int n;
    int target;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> target;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if ((a[l] + a[r]) == target)
        {
            cout << a[l] << " and " << a[r] << endl;
        update1:
            if (a[l] == a[l + 1])
            {
                cout << a[l + 1] << " and " << a[r] << endl;
                l++;
                goto update1;
            }
        update2:
            if (a[r] == a[r - 1])
            {
                cout << a[l] << " and " << a[r - 1] << endl;
                r--;
                goto update2;
            }
            else
            {
                l++;
                r--;
            }
        }
        else if ((a[l] + a[r]) > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return 0;
}