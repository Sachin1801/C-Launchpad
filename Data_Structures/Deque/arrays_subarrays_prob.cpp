#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    int a[100000];
    int k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    //we have to process the fist k elements separately
    deque<int> q(k); // creating a deque with the maximuym size as k of the deque
    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() && a[i] > q.back())
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    //Process the remaining element
    for (; i < n; i++)
    {
        cout << a[q.front()] << " ";

        //1. remove the elements from the deque which are not the part of the next window (contraction process )
        while ((!q.empty() && q.front() <= i - k))
        {
            q.pop_front();
        }
        //2. Remove the4 elements which are not useful and are in the window
        while ((!q.empty() && a[i] >= a[q.back()]))
        {
            q.pop_back();
        }
        //3. Add the new elements (expansion process)
        q.push_back(i);
    }
    cout << a[q.front()] << endl;
    return 0;
}