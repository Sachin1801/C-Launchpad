#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> s;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            s.insert(arr[i]);
        }
        int queries;
        cin >> queries;
        for (int i = 0; i < queries; i++)
        {
            int temp;
            cin >> temp;
            if (s.count(temp))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}