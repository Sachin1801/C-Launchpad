#include <iostream>
#include <unordered_map>
using namespace std;

int longestsubarrayksum(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == k)
        {
            len = max(len, i + 1);
        }
        if (m.find(pre - k) != m.end())
        {
            len = max(len, i - m[pre - k]);
        }
        else
        {
            // stroe the occ of the number occ at the first time
            m[pre] = i;
        }
    }
    return len;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << longestsubarrayksum(arr, n, k);
    return 0;
}