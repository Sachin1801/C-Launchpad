#include <iostream>
#include <queue>
using namespace std;

// Algorithm
// 1)Use the min heap approach and pick the smallest 2 numbers from thew array
// 2)Add the new rope in the min heap
// 3)Repeat until the last rope is left

int join_ropes(int ropes[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);
    int cost = 0;
    while (pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        int new_cost = A + B;
        cost += new_cost;
        pq.push(new_cost);
    }
    return cost;
}

int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = 4;
    cout << join_ropes(ropes, n) << endl;
    return 0;
}