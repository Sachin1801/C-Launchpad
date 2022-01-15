#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// classifying DSU with path compression and Union by rank

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }
        // recursive case
        return parent[i] = find(parent[i]);
    }

    // Unite - Union (we are naming it unite as union is a standard function name in c++)
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            // union by rank
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addedge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    int kruskal_mst()
    {
        // 1. Sort all the edges based upon the weight of the edge
        sort(edgelist.begin(), edgelist.end());

        DSU s(V);

        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take that list in mst if it doesn't form a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main()
{
    // Graph g(6);
    // g.addedge(0, 1, 1);
    // g.addedge(1, 3, 3);
    // g.addedge(3, 2, 4);
    // g.addedge(2, 0, 2);
    // g.addedge(0, 3, 2);
    // g.addedge(1, 2, 2);

    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addedge(x - 1, y - 1, w);
    }
    cout << g.kruskal_mst() << endl;
    return 0;
}