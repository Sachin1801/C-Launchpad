#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    int qno;
    int price;
    while (n--)
    {
        cin >> qno; // query number to be entered
        if (qno == 2)
        {
            cin >> price;
            s.push(price);
        }
        if (qno == 1 and !s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
        else if (qno == 1 and s.empty())
        {
            cout << "No Code" << endl;
        }
    }
    return 0;
}