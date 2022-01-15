#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq; // min priority queue

    // insert the 0th element of each array in the priority queue
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    // remove the elements one by one from the min heap and add to the result vector
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;  // row in which element is present
        int y = current.second.second; // column in which the element is present
        result.push_back(element);
        // you need to push the next element in the pq from the array from which the element was removed
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arr = {{2, 6, 12, 15},
                               {1, 3, 14, 20},
                               {3, 5, 8, 10}};

    vector<int> output = mergeKSortedArrays(arr);
    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}