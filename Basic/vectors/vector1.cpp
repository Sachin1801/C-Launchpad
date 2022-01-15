#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // some ways in which you can create and intialise a vector
    vector<int> a;
    vector<int> b(5, 10);              // It means the vector have 5 values and all the 5 values in it are initialised by 10
    vector<int> c(b.begin(), b.end()); // copy all the elements of vector b in vector c
    vector<int> d{1, 2, 3, 10, 15};    // vector is initialised with values

    //Look at how we can iterate over the vector
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << ",";
    }
    cout << endl;
    for (auto it = b.begin(); it != b.end(); it++) // in place of auto we can write vector<int>::iterator
    {
        cout << (*it) << ","; // it here acts like a pointer which iterates over the vector
    }
    cout << endl;

    //For each loop
    for (int x : d) // Meaning - we are iterating over every integer(x) that lies in the vector d , we
    {
        cout << x << ",";
    }
    cout << endl;

    //discuss more functions

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no); // Meaning - Adds element to the end of the vector
    }
    for (int x : v)
    {
        cout << x << ",";
    }
    cout << endl;

    //understand the differences between the two vectors d and v with the same size (5) , At the memory level
    cout << v.size() << endl;
    cout << v.capacity() << endl; // Size of the underlying array
    cout << v.max_size() << endl; // maximum number of elements that a vector can hold at the worst case accto available memory in t he system

    cout << d.size() << endl;
    cout << d.capacity() << endl; // Size of the underlying array
    cout << d.max_size() << endl;

    return 0;
}