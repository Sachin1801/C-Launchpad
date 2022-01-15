#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap; // we will set it true if the heap is min heap

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

    void heapify(int idx)
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
            heapify(min_idx);
        }
    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size); // this is to reserve in case the size is not given by the user
        v.push_back(-1);         // This is to fill the place at 0th position of vector
        minHeap = type;          // if the type provided by the user if given true then a min heap is formed and it is set true, otherwise false
    }

    void push(int d) // this push func is written for the minheap
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;

        // keep pushing to the the top till you reach the root node or you stop midway as the parent node is greater than the childern
        while (idx > 1 and compare(v[idx], v[parent])) // bottom top up approach
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    // return the topmost element of the heap
    int top()
    {
        return v[1];
    }

    // delete the largest no. or the smallest no. from the heap acc to the min or max heap
    void pop()
    {
        // swapping the first and the last element
        int last = v.size() - 1;
        swap(v[1], v[last]); // as the smallest in minheap will always be the root node
        v.pop_back();
        // to bring the root node back to its suitable position to get the heap tree condition to satisfy
        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{
    // give some initial size or type
    Heap h;
    // the above heap will automatically be a min heap , if we initialise it with a constuctor then it can be a max heap as well
    //  Heap h(10,false); for max heap example
    int n; // size of the vector
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }

    // remove all the elements one by one
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    return 0;
}