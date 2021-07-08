#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        vector<int> v(x);
        for (int j = 0; j < x; j++)
        {
            cin >> v[i] ;
        }
        next_permutation(v.begin(), v.end());
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    return 0;
}