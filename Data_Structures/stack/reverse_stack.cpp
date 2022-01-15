#include <stack>
#include <iostream>
using namespace std;

int main()
{
    stack<int> s1;
    stack<int> s2;
    int n;
    cin >> n; // number of elements to be entered in a stack
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        s1.push(d);
    }
    for (int i = 0; i < n; i++)
    {
        int x = s1.top();
        s1.pop();
        for (int j = 0; j < n - i - 1; j++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}