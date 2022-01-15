#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, w, h, n;
    cin >> t;
    int x[400001], y[400001];
    while (t--)
    {
        cin >> w >> h >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        // sorting of the coordinates
        sort(x, x + n);
        sort(y, y + n);

        // delta x and delta y
        int dx = x[0] - 1;
        int dy = y[0] - 1;
        for (int i = 1; i < n; i++)
        {
            dx = max(dx, x[i] - x[i - 1] - 1);
            dy = max(dy, y[i] - y[i - 1] - 1);
        }
        // corner case
        dx = max(dx, w - x[n - 1]);
        dy = max(dy, h - y[n - 1]);

        cout << dx * dy << endl;
    }
    return 0;
}