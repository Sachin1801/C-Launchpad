#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.pop_back();

    cout << "Capacity " << v.capacity() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;

    return 0;
}