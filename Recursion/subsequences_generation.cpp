#include <iostream>
using namespace std;

void generate_subsequences(char *in, char *out, int i, int j, int ans)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    //recursive case
    // including the next character
    out[j] = in[i];
    generate_subsequences(in, out, i + 1, j + 1, ans + 1);
    //excluding the next character
    generate_subsequences(in, out, i + 1, j, ans + 1);
    cout << endl;
    cout << ans;
}

int main()
{
    char input[] = {"abc"};
    char output[10];
    generate_subsequences(input, output, 0, 0, 0);

    return 0;
}