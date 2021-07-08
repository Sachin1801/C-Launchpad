#include <iostream>
using namespace std;

bool arrangementofcows(int n, int c, int a[], int mid)
{
    int last_cow = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - last_cow >= mid)
        {
            last_cow = a[i];
            cnt++;
            if (cnt == c)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N; //number of stalls
    cin >> N;
    int c; //Number of cows
    cin >> c;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a, a + N);
    int s = 0;
    int e = a[N - 1] - a[0];
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arrangementofcows(N, c, a, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}