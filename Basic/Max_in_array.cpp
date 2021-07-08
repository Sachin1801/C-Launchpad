#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100];
    int max;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    cout << max << endl;
    return 0;
}