#include <iostream>
#include <stack>
using namespace std;

bool isValidExp(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            if (stk.empty() || stk.top() != '(')
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
    }
    return stk.empty();
}
int main()
{
    string s;
    cin >> s;

    if (isValidExp(s))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}