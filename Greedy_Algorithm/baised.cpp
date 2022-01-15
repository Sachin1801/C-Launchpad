#include <iostream>
#include <algorithm>
using namespace std;

int abs(int i, int j)
{
    if (i - j > 0)
    {
        return i - j;
    }
    return j - i;
}

int main()
{
    int t;
    cin >> t;
    int n;
    int freq[100000] = {0};
    while (t--)
    {
        memset(freq, 0, sizeof(freq));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string name;
            int rank;
            cin >> name >> rank;
            freq[rank]++;
        }
        // Greedy Approach - assign the team to the nearest rank available
        int actual_rank = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            while (freq[i])
            {
                sum += abs(actual_rank, i);
                freq[i]--;
                actual_rank++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}