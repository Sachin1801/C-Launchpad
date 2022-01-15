#include <iostream>
#include <unordered_set>
using namespace std;

int findlargestSeq(int a[], int n)
{
    unordered_set<int> s;
    int max_len = 1;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i] - 1) == s.end())
        {
            int next_no = a[i] + 1;
            int str_len = 1;
            while (s.find(next_no) != s.end())
            {
                next_no += 1;
                str_len++;
            }
            max_len = max(max_len, str_len);
        }
    }
    return max_len;
}

int main()
{
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17}; // 10
    int n = sizeof(arr) / sizeof(int);
    cout << findlargestSeq(arr, n) << endl;
    return 0;
}