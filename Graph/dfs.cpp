#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        // recursive funtion that will traverse the graph
        cout << src << " ";
        visited[src] = true;
        // go to all nhbr of that nodes that is not visited
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool> visited;
        // Mark all the nodes at not visited in the beginning
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // call the helper function
        dfs_helper(src, visited);
    }
};
int main()
{
    Graph<int> g;
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);
    g.dfs(0);
    return 0;
}