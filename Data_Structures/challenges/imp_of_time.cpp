#include <iostream>
#include <queue>
using namespace std;

int impoftime(queue<int> q1, queue<int> q2, int n)
{
    int count = 0;
    if (n == 0)
    {
        return count;
    }
    while (!q2.empty())
    {
        if (q1.front() == q2.front())
        {
            count++;
            q1.pop();
            q2.pop();
        }
        else
        {
            while (q1.front() != q2.front())
            {
                int temp = q1.front();
                q1.pop();
                q1.push(temp);
                count++;
            }
            count++;
            q1.pop();
            q2.pop();
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    queue<int> q1, q2;
    while (q1.size() != n)
    {
        int no;
        cin >> no;
        q1.push(no);
    }
    while (q2.size() != n)
    {
        int no;
        cin >> no;
        q2.push(no);
    }
    int ans = impoftime(q1, q2, n);
    cout << ans << endl;
    return 0;
}