#include <iostream>
using namespace std;

void indices(int *a, int n, int i, int key)
{
    // base case
    if (i > n)
    {
        return;
    }
    //recursive case
    if (a[i] == key)
    {
        a[i] = 1;
        indices(a, n, i + 1, key);
    }
    else
    {
        a[i] = 0;
        indices(a, n, i + 1, key);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int key;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;
    indices(a, n, 0, key);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}