#include <iostream>
#include <set>
#include <list>
#include <unordered_map>
#include <cstring>
#include <limits.h>
using namespace std;

template <typename T>

class Graph
{
    unordered_map<T, list<pair<T, int>>> m;

public:
    void addedge(T u, T v, int dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj()
    {
        // let us try to print the adj list
        // Iterate over all the key value pair in the map
        for (auto j : m)
        {
            cout << j.first << "->";
            for (auto l : j.second)
            {
                cout << " (" << l.first << " , " << l.second << ") ";
            }
            cout << endl;
        }
    }
    void DijkstraSSSP(T src)
    {
        unordered_map<T, int> dist;

        // set all the distance to infintiy
        for (auto j : m)
        {
            dist[j.first] = INT_MAX;
        }

        // Make a set to find a node with minimum distance
        set<pair<int, T>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty())
        {
            // Find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            // iterate over the neighbour  / children of the current node
            for (auto childPair : m[node])
            {
                if (nodeDist + childPair.second < dist[childPair.first])
                {
                    // In the set , updation is not possible
                    // We have to remove the old pair , and insert the new pair to simulate updation
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    // Insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for (auto d : dist)
        {
            cout << d.first << " Located at a distance " << d.second << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addedge("Amristar", "Delhi", 1);
    g.addedge("Amristar", "Jaipur", 4);
    g.addedge("Jaipur", "Delhi", 2);
    g.addedge("Jaipur", "Mumbai", 8);
    g.addedge("Bhopal", "Agra", 2);
    g.addedge("Mumbai", "Bhopal", 3);
    g.addedge("Agra", "Delhi", 1);
    // g.printAdj();
    g.DijkstraSSSP("Amritsar");
    return 0;
}