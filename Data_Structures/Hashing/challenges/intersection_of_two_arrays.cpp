#include <iostream>
#include <set>
using namespace std;

void check_intersection(set<int> s1, set<int> s2, int size)
{
    int ansarr[100];
    for (auto x : s1)
    {
        int temp = min(s1.count(x), s2.count(x));
        for (int i = 0; i < temp; temp++)
        {
            ansarr[i] = x;
        }
    }
    int anslen = sizeof(ansarr) / sizeof(int);
    cout << "[";
    for (int i = 0; i < anslen; i++)
    {
        cout << ansarr[i];
        if (i < (anslen - 1))
        {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    int size;
    cin >> size;
    int arr1[size];
    int arr2[size];
    set<int> s1;
    set<int> s2;
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
        s1.insert(arr1[i]);
    }
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i];
        s2.insert(arr2[i]);
    }
    check_intersection(s1, s2, size);
    return 0;
}