#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 20, 40, 40, 40, 50, 80, 100};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    //To binary search an element in the array
    bool present = binary_search(arr, arr + n, 40);
    if (present)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    //upper and lower bound
    auto lb = lower_bound(arr, arr + n, 40);
    auto ub = upper_bound(arr, arr + n, 40);
    cout << "Lower bound is" << (lb - arr) << endl;
    cout << "Upper bound is " << (ub - arr) << endl;
    return 0;
}