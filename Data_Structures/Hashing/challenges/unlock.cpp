#include <iostream>
#include <map>
using namespace std;

void permute_code(int *arr, int n, int k, map<int, int> m)
{
    int num = n;
    int best_pos;
    for (int i = 0; i < n; i++)
    {
        int best_pos = n - num;
        if (k == 0)
        {
            break;
        }
        if (arr[i] < num)
        {
            int temp = m[num];
            m[arr[i]] = temp;
            m[num] = i;
            swap(arr[i], arr[temp]);
            k--;
            num--;
        }
        if (arr[best_pos] == num)
        {
            num--;
        }
        if (arr[i] > num)
        {
            num--;
        }
    }
    for (auto x : m)
    {
        cout << x.first << " : " << x.second << endl;
    }
    return;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    map<int, int> m;
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
        m[arr[i]] = i;
    }
    permute_code(arr, n, k, m);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for (auto x : m)
    {
        cout << x.first << " : " << x.second;
    }
    return 0;
}