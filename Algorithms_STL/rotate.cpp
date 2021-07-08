#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(int);
    //inbuilt fuction to rotate
    rotate(a, a + 2, a + n); // parameters are (begin of array , from where to rotate, till where to rotate)

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
    //rotate a vector
    //How to create a vector
    vector<int> v{10, 20, 30, 40, 50};
    rotate(v.begin(), v.begin() + 3, v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;
}