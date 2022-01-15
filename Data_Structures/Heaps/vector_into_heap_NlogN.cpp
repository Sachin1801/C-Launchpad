#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

bool minHeap = false;

bool compare(int a, int b)
{
    if (minHeap)
    {
        return a < b;
    }
    else
    {
        return a > b;
    }
}

// O(NlogN)
void buildheap(vector<int> &v)
{
    for (int i = 2; i < v.size(); i++) // we have started from the 2nd index from the vector as we are assuming that 0th idx is not the part of heap
    {
        int idx = i;
        int parent = i / 2;
        while (idx > 1 and v[idx] > v[parent]) // this condition we have taken for the max heap
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

void heapify(vector<int> &v, int idx)
{
    int left = 2 * idx;
    int right = left + 1;
    int min_idx = idx;
    int last = v.size() - 1;
    if (left <= last && compare(v[left], v[idx]))
    {
        min_idx = left;
    }
    if (right <= last && compare(v[right], v[min_idx]))
    {
        min_idx = right;
    }
    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx);
    }
}

// O(N)- More optimised approach of the problem
void buildHeapOptimised(vector<int> &v)
{
    for (int i = (v.size() - 1 / 2); i >= 1; i--)
    {
        heapify(v, i);
    }
}

int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4}; // heap
    print(v);
    cout << endl;
    buildHeapOptimised(v);
    print(v);

    return 0;
}