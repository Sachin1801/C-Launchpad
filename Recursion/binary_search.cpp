#include <iostream>
using namespace std;

void binary(int a[], int n, int s, int e)
{
    int mid = (s + e) / 2;
    if (a[mid] == n)
    {
        cout << "Number found at " << mid << endl;
    }
    if (a[mid] < n)
    {
        s = mid + 1;
        binary(a, n, s, e);
    }
    if (a[mid] > n)
    {
        e = mid - 1;
        binary(a, n, s, e);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(a) / sizeof(int);
    int n;
    cin >> n;
    int s = 0;
    int e = size - 1;
    binary(a, n, s, e);
    return 0;
}