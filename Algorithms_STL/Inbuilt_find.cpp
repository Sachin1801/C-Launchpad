#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 100, 110};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    auto it = find(arr, arr + n, key);
    int index = it - arr;
    if (index == n)
    {
        cout << key << " not found in array";
    }
    else
    {
        cout << " found in the array at index " << index << endl;
    }
    return 0;
}