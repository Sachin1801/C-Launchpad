#include <iostream>
using namespace std;

//Generate Balanced brackets using N Pairs of round brackets

void generate_brackets(int n, char *out, int idx, int open, int close)
{
    //base case
    if (idx == (2 * n))
    {
        out[idx] = '\0';
        cout << out << endl;
        return;
    }
    //recursive cases
    //2 options whether we can put open or close brackets
    if (open < n)
    {
        out[idx] = '(';
        generate_brackets(n, out, idx + 1, open + 1, close);
    }
    if (close < open)
    {
        out[idx] = ')';
        generate_brackets(n, out, idx + 1, open, close + 1);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    char output[1000];
    int idx = 0;
    generate_brackets(n, output, idx, 0, 0);
    return 0;
}