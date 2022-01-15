#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<pair<int, int>> s;
    s.insert(make_pair(10, 1));
    s.insert(make_pair(10, 5));
    s.insert(make_pair(20, 1));
    s.insert(make_pair(20, 100));
    s.insert(make_pair(5, 1));
    s.insert(make_pair(5, 3));

    s.erase(make_pair(5, 3)); // This will erase the pair (5,3) pair from the set
    s.insert(make_pair(5, 4));

    auto it = s.lower_bound(make_pair(20, 1)); //this will print 20,1 only as lowerbound condn is <=
    cout << it->first << " & " << it->second << endl;

    auto it2 = s.upper_bound(make_pair(20, 1)); //this will print 20,100 as upperbound condn is >
    cout << it2->first << " & " << it2->second << endl;

    for (auto p : s) //for every pair p in set s
    {
        cout << p.first << " and " << p.second << endl;
    }
}