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
    void addedge(T x, T y)
    {
        l[x].push_back(y);
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        // recursive funtion that will traverse the graph

        visited[src] = true;
        // go to all nhbr of that nodes that is not visited
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited, ordering);
            }
        }
        // at this point
        ordering.push_front(src);
        return;
    }

    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        // Mark all the nodes at not visited in the beginning
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        // call the helper function

        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                dfs_helper(node, visited, ordering);
            }
        }
        for (auto node : ordering)
        {
            cout << node << "---> ";
        }
    }
};
int main()
{
    Graph<string> g;
    g.addedge("Python", "DataPreprocessing");
    g.addedge("Python", "PyTorch");
    g.addedge("Python", "ML");
    g.addedge("DataPreprocessing", "ML");
    g.addedge("PyTorch", "DL");
    g.addedge("ML", "DL");
    g.addedge("DL", "FaceRecognition");
    g.addedge("DataSet", "FaceRecognition");
    g.dfs();
    return 0;
}
