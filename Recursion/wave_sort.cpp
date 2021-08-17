#include <iostream>
using namespace std;

int main()
{
    int a[] = {2, 8, 9, 4, 5, 3, 0};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i += 2)
    {
        //compare with the previous element
        if (i != 0 and a[i] < a[i - 1])
        {
            swap(a[i], a[i - 1]);
        }

        //compare with the next element
        if (i != (n - 1) and a[i] < a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}