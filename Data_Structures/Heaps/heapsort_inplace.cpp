#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

void heapify(vector<int> &v, int idx, int size)
{
    int left = 2 * idx;
    int right = left + 1;
    int max_idx = idx;
    int last = size - 1;
    if (left <= last && compare(v[left], v[idx]))
    {
        max_idx = left;
    }
    if (right <= last && compare(v[right], v[max_idx]))
    {
        max_idx = right;
    }
    if (max_idx != idx)
    {
        swap(v[idx], v[max_idx]);
        heapify(v, max_idx, size);
    }
}

void print(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void buildHeapOptimised(vector<int> &v)
{
    for (int i = (v.size() - 1 / 2); i >= 1; i--)
    {
        heapify(v, i, v.size());
    }
}

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

void heapsort(vector<int> &arr)
{
    buildHeapOptimised(arr);
    int n = arr.size();
    while (n > 1)
    {
        swap(arr[1], arr[n - 1]); // as the last index is at the n-1th index
        // remove the element from the heap i.e shrink the size of the vector/array temporary
        n--;
        heapify(arr, 1, n);
    }
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    heapsort(v);
    print(v);
    return 0;
}