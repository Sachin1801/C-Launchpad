#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;

        for (auto nbr : l[node])
        {
            // two cases
            if (!visited[nbr])
            {
                // recursively check for the other nodes in the neighbourhood
                bool cycle_mila = cycle_helper(nbr, visited, node);
                if (cycle_mila)
                {
                    return true;
                }
            }
            // nbr is visited but nbr should not be parent
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle()
    {
        // check for cycle in directed graph
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        return cycle_helper(0, visited, -1);
    }
};

int main()
{
    Graph g(5);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 0);

    if (g.contains_cycle())
    {
        cout << "Yes it contains a cycle" << endl;
    }
    else
    {
        cout << "No, it does not contains a cycle " << endl;
    }
    return 0;
}