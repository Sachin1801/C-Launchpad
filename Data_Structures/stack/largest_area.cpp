#include <stack>
#include <iostream>
using namespace std;

int prev_max_area(int arr[], stack<int> &s, int curr)
{
    int area = 0;
    if (s.top() < curr)
    {
        return 0;
    }
    if (s.empty())
    {
        return 0;
    }
    if (s.top() < curr)
    {
        int top = s.top();
        s.pop();
        area = max((arr[top] * (curr - s.top() - 1)), prev_max_area(arr, s, curr));
    }
    return area;
}

bool isempty(stack<int> s)
{
    s.pop();
    return s.empty();
}

int largest_area(int arr[], int size)
{
    stack<int> s;
    int ans = 0;
    int area = 0;
    for (int i = 0; i <= size; i++)
    {
        if (s.empty())
        {
            s.push(i);
        }
        if ((arr[i] < arr[s.top()]) && isempty(s))
        {
            int top = s.top();
            s.pop();
            area = arr[top] * i;
            ans = max(area, ans);
            s.push(i);
        }
        else if (arr[i] > arr[s.top()])
        {
            s.push(i);
        }
        else
        {
            area = prev_max_area(arr, s, i);
            ans = max(ans, area);
            s.push(i);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    int ans = largest_area(arr, n);
    cout << ans << endl;
    return 0;
}