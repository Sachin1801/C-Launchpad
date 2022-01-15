#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>
using namespace std;

class Graph
{
    // Adj List
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addedge(string x, string y, bool bidir, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (bidir)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printadjlist()
    {
        // iterate over all the keys in the map
        for (auto p : l)
        {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout << city << "->";
            for (auto nbr : nbrs)
            {
                string dest = nbr.first;
                int dist = nbr.second;
                cout << dest << " " << dist << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addedge("A", "B", true, 20);
    g.addedge("B", "D", true, 40);
    g.addedge("A", "C", true, 10);
    g.addedge("C", "D", true, 40);
    g.addedge("A", "D", false, 50);
    g.printadjlist();
    return 0;
}