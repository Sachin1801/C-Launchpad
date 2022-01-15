#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
    cout << "Caomparing " << a << " and " << b << endl;
    return a < b;
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //Calling function as a parameter internally
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " , ";
    }
    return 0;
}