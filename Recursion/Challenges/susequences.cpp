#include <iostream>
using namespace std;

int subsequences(string str, char out[], int i, int j)
{
    //base case
    if (i == str.length())
    {
        out[j] = '\0';
        cout << out << " ";
        return 1;
    }
    //recursive case
    //including the next character
    int ans = 0;
    //excluding the next character
    ans += subsequences(str, out, i + 1, j);
    out[j] = str[i];
    ans += subsequences(str, out, i + 1, j + 1);
    return ans;
}

int main()
{
    string str;
    cin >> str;
    char output[100];
    int ans = subsequences(str, output, 0, 0);
    cout << endl
         << ans;
    return 0;
}