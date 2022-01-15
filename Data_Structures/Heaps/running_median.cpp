#include <iostream>
#include <queue>
using namespace std;

// Running median of integers
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        priority_queue<int> leftheap;                             // max heap
        priority_queue<int, vector<int>, greater<int>> rightheap; // min heap
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        leftheap.push(a[0]);
        float med = a[0];
        cout << med << " "; // the first element entered is the median itself
        for (int i = 1; i < n; i++)
        {
            int d;
            d = a[i];
            // logic to calculate the median
            if (leftheap.size() > rightheap.size())
            {
                if (d <= med)
                {
                    rightheap.push(leftheap.top());
                    leftheap.pop();
                    leftheap.push(d);
                    med = (leftheap.top() + rightheap.top()) / 2.0;
                }
                else
                {
                    rightheap.push(d);
                    med = (leftheap.top() + rightheap.top()) / 2.0;
                }
            }
            else if (leftheap.size() == rightheap.size())
            {
                if (d < med)
                {
                    leftheap.push(d);
                    med = leftheap.top();
                }
                else
                {
                    rightheap.push(d);
                    med = rightheap.top();
                }
            }
            else
            {
                if (d >= med)
                {
                    leftheap.push(rightheap.top());
                    rightheap.pop();
                    rightheap.push(d);
                }
                else
                {
                    leftheap.push(d);
                }
                med = (leftheap.top() + rightheap.top()) / 2.0;
            }
            cout << med << " ";
        }
    }
    return 0;
}