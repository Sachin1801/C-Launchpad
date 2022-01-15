#include <iostream>
using namespace std;

#define INT_MAX 999999

int n = 4;
// Adj matrix which defines the graph
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

int VISITED_ALL = (1 << n) - 1;

int tsp(int mask, int pos)
{
    // base case
    if (mask == VISITED_ALL)
    {
        return dist[pos][0];
    }
    int ans = INT_MAX;
    // Try to go to an unvisited city
    for (int city = 0; city < n; city++)
    {
        // checking if visited or not
        if (mask & (1 << city) == 0) // this means that the city isn't visited
        {
            int newans = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newans);
        }
    }
    return ans;
}

int main()
{
    cout << tsp(1, 0) << endl;
    return 0;
}