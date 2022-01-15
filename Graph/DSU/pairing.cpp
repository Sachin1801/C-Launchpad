#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addedge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    // find func
    int findset(int i, int parent[])
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }
        // path compression
        return parent[i] = findset(parent[i], parent);
    }

    // union func
    void union_set(int x, int y, int parent[], int rank[])
    {
        int s1 = findset(x, parent);
        int s2 = findset(y, parent);
        if (s1 != s2)
        {
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

    int pairing()
    {
        // init DSU logic
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
        // Code logic
        int ans = 0;
        for (auto node : l)
        {
            int i = node.first;
            int j = node.second;
            int s1 = findset(i, parent);
            int s2 = findset(j, parent);
            union_set(s1, s2, parent, rank);
        }
        for (int i = 0; i < V; i++)
        {
            ans += V - rank[findset(i, parent)];
        }
        delete[] parent;
        delete[] rank;
        return (ans / 2);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addedge(x, y);
    }
    cout << g.pairing() << endl;
    return 0;
}