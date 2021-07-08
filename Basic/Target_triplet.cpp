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
    int temp;

    for (int j = 0; j < n - 4; j++)
    {
        int i = j;
        temp = target - a[i];
        int l = j + 1;
        int r = n - 1;
        while (l < r)
        {
            if ((a[l] + a[r]) == temp)
            {
                cout << a[i] << ", " << a[l] << " and " << a[r] << endl;
                l++;
                r--;
            }
            else if ((a[l] + a[r]) > temp)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return 0;
}