#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // priority_queue<int> pq; // for max heap
    // for min heap
    priority_queue<int, vector<int>, greater<int>> pq; // for min heap / min priority queue
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        pq.push(no); // O(logN)
    }

    // remove the elements from the heap while it isn't empty
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}