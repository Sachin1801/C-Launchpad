#include <iostream>
using namespace std;

int last_index(int arr[], int i, int m)
{
    //base case
    if (i == 0)
    {
        if (arr[i] == m)
        {
            return i;
        }
        return -1;
    }
    //recursive case
    if (arr[i] == m)
    {
        return i;
    }
    int rr = last_index(arr, i - 1, m);
    return rr;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    cout << last_index(a, n - 1, m);
    return 0;
}