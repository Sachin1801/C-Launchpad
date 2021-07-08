#include <iostream>
using namespace std;

int find(int n, int a[], int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (key < a[mid])
        {
            e = mid - 1;
        }
        else if (key == a[mid])
        {
            ans = mid;
            return ans;
        }
        else
        {
            s = mid + 1;
        }
    }
    if (a[s] == key)
    {
        return s;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << find(N, a, key) << endl;
    return 0;
}