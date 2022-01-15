#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int t, n, s, e;
    cin >> t;

    vector<pair<int, int>> v;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }
        // Activity Selectiopn algorithm
        // Sort according to their ending time
        sort(v.begin(), v.end(), compare);
        // start picking
        int res = 1;           // number of activities that we can do
        int fin = v[0].second; // finishing time of the fisrt activity that finishes first which we have already picked

        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= fin)
            {
                fin = v[i].second;
                res++;
            }
        }
        cout << res << endl;
        v.clear(); // we need to clear this vector so that we can store the start and end points for the next test cases
    }
    return 0;
}