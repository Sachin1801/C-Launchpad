#include <iostream>
using namespace std;

bool compare(int a, int b)
{
    cout << "Comparing " << a << "and " << b << endl;
    //the statement below is to write when we want to print the array in the descending order, otherwise write a<b;
    return a > b;
}

int main()
{
    int n, key;
    cin >> n;
    int a[1000];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, compare);

    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i];
    }
}