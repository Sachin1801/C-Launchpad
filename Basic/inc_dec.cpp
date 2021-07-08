#include <iostream>
using namespace std;

bool sequence(long int s[], int n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        if (s[i] < s[i + 1])
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if (i == n - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long int s[1000];
    int n;
    cin >> n;

    for (int i = 0; i <= n - 1; i++)
    {
        cin >> s[i];
    }
    cout << sequence(s, n);
    return 0;
}