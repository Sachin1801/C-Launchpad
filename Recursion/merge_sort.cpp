#include <iostream>
using namespace std;

void merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[s + 1];
    while (i <= mid && j <= e)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= e)
    {
        temp[k++] = a[j++];
    }
    //We need to copy all elements to the array a from array temp
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

void mergesort(int a[], int s, int e)
{
    //Base case 1 or 0 elements
    if (s >= e)
    {
        return;
    }
    //Follow 3 steps
    //1.Divide the array in 2 parts
    int mid = (s + e) / 2;
    //recursively sort the arrays s,mid and mid+1,e
    mergesort(a, s, mid);
    mergesort(a, mid + 1, e);

    //Merge two parts
    merge(a, s, e);
}

int main()
{
    long int n;
    cin >> n;
    long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}