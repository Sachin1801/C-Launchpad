#include <iostream>
using namespace std;

int sorted(int a[], int n)
{
    //base case
    if (n == 1 || n == 0)
    {
        return 1;
    }
    //recursive case
    if (a[n - 1] < a[n - 2])
    {
        return 0;
    }
    return sorted(a, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (sorted(arr, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}