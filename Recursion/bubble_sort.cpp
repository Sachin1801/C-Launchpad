#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    //base case
    if (n == 1)
    {
        return;
    }
    //recursive case
    for (int j = 0; j < n - 1; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
    }
    bubble_sort(a, n - 1);
}

void bubble_sort_recursively(int a[], int j, int n)
{
    //base case
    if (n == 1)
    {
        return;
    }
    if (j == n - 1)
    {
        return bubble_sort_recursively(a, 0, n - 1);
    }
    //rec case
    if (a[j] > a[j + 1])
    {
        swap(a[j], a[j + 1]);
    }
    bubble_sort_recursively(a, j + 1, n);
    return;
}

int main()
{
    int a[] = {2, 7, 9, 4, 1, 3};
    int n = 6;
    bubble_sort_recursively(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}