#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <list>
using namespace std;

class Graph
{
    list<int> *l;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    void topological_sort()
    {
        // indegree
        int *indegree = new int[v]; // creating a new array - it is a way of creating an array
        // 0 indegree initiating
        for (int i = 0; i < v; i++)
        {
            indegree[i] = 0;
        }

        // update the indegree
        for (int i = 0; i < v; i++)
        {
            for (auto y : l[i])
            {
                indegree[y]++;
            }
        }
        // bfs
        queue<int> q;
        // 1. find nodes with 0 indegree
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // start removing elements from the queue
        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.topological_sort();
    return 0;
}