#include <iostream>
#include <stack>
#include <string>
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
    void addedge(int x, int y, bool directed = true)
    {
        l[x].push_back(y);
        if (!directed)
        {
            l[y].push_back(x);
        }
    }

    bool cycle_helper(int node, bool *visited, bool *stack)
    {
        visited[node] = true;
        stack[node] = true;
        for (int nbr : l[node])
        {
            // two cases
            if (stack[nbr] == true)
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                bool cycle_mila = cycle_helper(nbr, visited, stack);
                if (cycle_mila == true)
                {
                    return true;
                }
            }
        }
        // leave a node
        stack[node] = false;
        return false;
    }

    bool contains_cycle()
    {
        // check for cycle in directed graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = stack[i] = 0;
        }

        return cycle_helper(0, visited, stack);
    }
};

int main()
{
    Graph g(7);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 4);
    g.addedge(4, 5);
    g.addedge(1, 5);
    g.addedge(5, 6);
    g.addedge(4, 2);

    if (g.contains_cycle())
    {
        cout << "Yes it contains a cycle " << endl;
    }
    else
    {
        cout << "No, it does not contain a cycle";
    }
    return 0;
}