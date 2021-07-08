#include <iostream>
using namespace std;

int merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100000];
    int cnt = 0;
    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    // to transfer the remaining elements in temp when one small array is exhausted
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }
    // Copy all the elemats back to the original array a
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
    return cnt;
}

int inversion_sort(int *a, int s, int e)
{
    //base case
    if (s >= e)
    {
        return 0;
    }
    //merge sort
    int mid = (s + e) / 2;
    int x = inversion_sort(a, s, mid);
    int y = inversion_sort(a, mid + 1, e);
    int z = merge(a, s, e); // cross inversions
    return x + y + z;
}

int main()
{
    int a[] = {1, 2, 5, 0, 3, 6};
    int n = sizeof(a) / sizeof(int);
    cout << inversion_sort(a, 0, n - 1) << endl;
    return 0;
}