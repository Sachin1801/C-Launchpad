#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }
    void addedge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        // most important part
        // init a min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // another array
        // Visited array that denotes whether a node has been included in MST or not
        bool *Visited = new bool[V]{0};
        int ans = 0;

        // begin
        Q.push({0, 0}); // weight,node
        // as the min heap will be sorted according to the first parameter that is the weight
        while (!Q.empty())
        {
            // pick out the edge with the minimum weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (Visited[to])
            {
                continue;
            }
            // otherwise take the current edge
            ans += weight;
            Visited[to] = 1;

            // add the new edges in the queue
            for (auto x : l[to])
            {
                if (Visited[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n, m; // n= no.of vertices and m= no.of edges
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addedge(x, y - 1, w);
    }
    cout << g.prim_mst() << endl;
    return 0;
}