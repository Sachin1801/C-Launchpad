#include <iostream>
using namespace std;

void countingsort(int a[])
{
    int min = min(a, a + n);
    int max = max(a, a + n);
    int range = (max - min) + 1;
    int count[10000] = {0};
    int countt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        count[temp] = count[temp] + 1;
    }
    //modifying the count array
    for (int i = 0; i < range; i++)
    {
        count[i] += count[i + 1];
    }
    int arr[range];
    for (int i = 0; i < n; i++)
    {
    }
}

int main()
{
    int n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    countingsort(a);
    return 0;
}