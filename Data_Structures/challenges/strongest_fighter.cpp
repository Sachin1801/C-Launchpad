#include <iostream>
#include <queue>
using namespace std;

void strongest_fighter(queue<int> q1, queue<int> q2)
{
    queue<int> temp;
    int maxi = q2.front();
    while (!q1.empty())
    {
        while (!q2.empty())
        {
            temp.push(q2.front());
            q2.pop();
            maxi = max(maxi, q2.front());
        }
        cout << maxi << " ";
        swap(temp, q2);
        q2.pop();
        q2.push(q1.front());
        q1.pop();
    }
    while (!q2.empty())
    {
        maxi = q2.front();
        q2.pop();
        maxi = max(maxi, q2.front());
    }
    cout << maxi << " ";
    return;
}

int main()
{
    int n;
    cin >> n;
    queue<int> q1;
    int i;
    while (n--)
    {
        cin >> i;
        q1.push(i);
    }
    int sg;
    cin >> sg;
    queue<int> q2;
    for (int j = 0; j < sg; j++)
    {
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
    }

    strongest_fighter(q1, q2);
    return 0;
}