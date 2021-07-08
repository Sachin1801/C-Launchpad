#include <iostream>
using namespace std;

int partition(int *a, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = a[e];
    for (; j <= e - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i = i + 1;
            //merge the element in the smaller region
            swap(a[i], a[j]);
        }
        //expand the larger region
    }
    // place the pivot element at the correct position
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(int *a, int s, int e)
{
    //base case
    if (s >= e)
    {
        return;
    }
    //recursive case
    int p = partition(a, s, e);
    // left part
    quicksort(a, 0, p);
    // right part
    quicksort(a, p + 1, e);
}

int main()
{
    //Quick sort
    int a[] = {2, 7, 8, 6, 1, 5, 4};
    int n = sizeof(a) / sizeof(int);
    quicksort(a, 0, n - 1);
    //print the sorted array
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}