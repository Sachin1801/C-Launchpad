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
    }

    void bfs(T src)
    {
        map<T, int> dist;
        queue<T> q;
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (int nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    // cout << dist[nbr];
                    // mark that neighbour as visited
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            cout << " Node " << node << " Distance frm src " << dist[node] << endl;
        }
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
    g.bfs(0);
    return 0;
}