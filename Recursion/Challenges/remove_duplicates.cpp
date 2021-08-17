#include <iostream>
#include <cstring>
using namespace std;

void remove_duplicates(string str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] != str[i + 1])
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
    remove_duplicates(str, n);
    return 0;
}