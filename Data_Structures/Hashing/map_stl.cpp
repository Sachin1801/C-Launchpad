#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    // 1.Insert
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);
    m["Banana"] = 60;

    // 2. Search
    string fruit;
    cin >> fruit;

    auto it = m.find(fruit);
    if (it != m.end())
    {
        cout << "Price of fruit " << fruit << " is " << m[fruit] << endl;
    }
    else
    {
        cout << "Fruit is not present " << endl;
    }

    // 3. Erase
    m.erase(fruit);

    // 4.Update the price
    m[fruit] += 22;

    // Another way to find a particular map
    // it stores unique key only once
    if (m.count(fruit))
    {
        cout << "Price is " << m[fruit] << endl;
    }
    else
    {
        cout << "Fruit is not present ";
    }
    m["Litchi"] = 80;
    m["Pineapple"] = 110;

    // Iterate over the pair values in the map
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " -> " << (*it).second << endl;
    }
    cout << endl;
    // Another way to traverse along all the pairs in the map
    for (auto x : m)
    {
        cout << x.first << " : " << x.second << endl;
    }
    return 0;
}