#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int cost)
    {
        l[u].push_back(make_pair(v, cost));
        l[v].push_back(make_pair(u, cost));
    }

    int dfs_helper(int node, bool *visited, int *count, int &ans)

        int dfs()
    {
        bool *visited = new bool[V];
        int *count = new int[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            count[i] = 0;
        }
        int ans = 0;
        dfs_helper(0, visited, count, ans);
        return ans;
    }
};

int main()
{

    return 0;
}