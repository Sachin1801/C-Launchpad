#include <iostream>
#include <cstring>
using namespace std;

void duplicate(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] == str[i + 1])
        {
            cout << str[i] << "*";
        }
        else
        {
            cout << str[i];
        }
    }
    return;
}

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    duplicate(str, n);
    return 0;
}