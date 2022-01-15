#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;
int main()
{
    int arr[] = {10, 20, 30, 30, 30, 20, 10};
    int n = sizeof(arr) / sizeof(int);
    multiset<int> m(arr, arr + n);

    //erase 20
    m.erase(20); // it erases all the occurences of 20

    //Iterate
    for (auto x : m)
    {
        cout << x << ",";
    }

    //can also insert using insert function
    m.insert(80);
    cout << endl;
    //count
    cout << m.count(10) << endl;

    //find
    auto it = m.find(30); //this will give us the first occ of 30 in the array
    cout << *it << endl;

    //Get all the elements which are equal to 30
    pair<It, It> range = m.equal_range(30);
    for (auto it = range.first; it != range.second; it++)
    {
        cout << *it << ",";
    }
    cout << endl;
    //Lower Bound and Upper nound in multiset
    for (auto it = m.lower_bound(10); it != m.upper_bound(77); it++)
    {
        cout << *it << "-";
    }

    return 0;
}