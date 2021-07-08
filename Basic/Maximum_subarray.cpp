#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1000];
    int currentsum;
    int maximumsum;
    int left, right;
    // cin the array;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currentsum = 0;
            for (int k = i; k <= j; k++)
            {
                currentsum += a[k];
            }
            // update maximum sum
            if (currentsum > maximumsum)
            {
                maximumsum = currentsum;
                left = i;
                right = j;
            }
        }
    }
    //print the maximum sum
    cout << maximumsum;

    //print the maximum sub array
    for (int i = left; i <= right; i++)
        cout << a[i] << ",";

    return 0;
}