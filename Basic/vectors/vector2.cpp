#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> d{1, 2, 3, 4, 5};
    //Pushback - 0(1) for most of the time
    d.push_back(10);
    for (int x : d)
    {
        cout << x << ",";
    }
    cout << endl;
    //Removes / Pops the last elemtn out of the vector
    d.pop_back();

    //To insert an element in between the vector
    d.insert(d.begin() + 3, 4, 100); // This means we are adding 4 times 100 , starting from the postion d.begin +3, i.e from the 4th position the new values will be inserted

    //to erase some elements from the middle
    d.erase(d.begin() + 2);                // It will remove the element at the third position in the vector
    d.erase(d.begin() + 2, d.begin() + 5); // This will remove multiple elemts from positon 3-6

    for (int x : d)
    {
        cout << x << ",";
    }
    cout << endl;
    //size
    cout << d.size() << endl;
    //capacity
    cout << d.capacity() << endl;

    //We avoid to shrink
    d.resize(21);
    cout << d.capacity() << endl;

    //remove all the elements from the vector
    d.clear();
    cout << d.size() << endl;
    //another method to check if the vector is empty of not
    if (d.empty())
    {
        cout << "The vector is no0w empty" << endl;
    }
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    cout << d.front() << endl; // to frint the front most element of the vector
    cout << d.back() << endl;

    //reserve function
    vector<int> v;
    v.reserve(1000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
        cout << "Capacity is " << v.capacity() << endl;
    }
    cout << v.capacity() << endl;
    for (int x : v)
    {
        cout << x << ",";
    }
    return 0;
}