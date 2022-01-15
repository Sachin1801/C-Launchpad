#include <stack>
#include <iostream>
using namespace std;

void stockspan(int prices[], int n, int span[])
{
    stack<int> s; // to store the indices of the days
    s.push(0);
    span[0] = 1;

    //loop for the rest of the days
    for (int i = 1; i <= n - 1; i++)
    {
        int currentprice = prices[i];
        //top most elements that is highesr than the current prices

        while (!s.empty() and prices[s.top()] <= currentprice)
        {
            s.pop();
        }
        if (!s.empty())
        {
            int prev_highest = s.top();
            span[i] = i - prev_highest;
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
}

int main()
{
    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int span[100000] = {0};
    stockspan(prices, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    cout << "END" << endl;
    return 0;
}