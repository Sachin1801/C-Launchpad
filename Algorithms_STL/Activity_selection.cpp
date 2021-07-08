#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), comp);

        int curr = v[0].first;
        int ans = 1;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].second <= curr)
            {
                ans++;
                curr = v[i].first;
            }
        }

        cout << ans << endl;
    }
}