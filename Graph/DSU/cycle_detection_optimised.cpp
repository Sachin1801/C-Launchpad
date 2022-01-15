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

    bool contains_cycle()
    {
        // DSU logic to check whether the graph contains the cycle or not
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;
            int s1 = findset(i, parent);
            int s2 = findset(j, parent);
            if (s1 != s2)
            {
                union_set(s1, s2, parent, rank);
            }
            else
            {
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(1, 4);
    if (g.contains_cycle())
    {
        cout << "Yes it contains a cycle " << endl;
    }
    else
    {
        cout << "No, it does not contain a cycle " << endl;
    }
    return 0;
}