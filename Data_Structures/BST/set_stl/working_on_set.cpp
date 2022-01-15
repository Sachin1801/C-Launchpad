#include <iostream>
#include <set>
using namespace std;

int main()
{
    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int n = sizeof(arr) / sizeof(int);

    set<int> s;
    //to insert into the set
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    s.erase(10);
    auto(it) = s.find(11);
    s.erase(it);

    //Print all thr elements
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << ",";
    } // without the above erase commands it prints 8.9,10,11,20 i.e in ordered form and only the unique elements
    return 0;
}