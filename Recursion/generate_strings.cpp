#include <iostream>
using namespace std;

void generate_strings(char *in, char *out, int i, int j)
{
    //base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    int digit;
    char ch;
    //rec case
    //only taking one integer at a time
    if (in[i + 1] != 0)
    {
        digit = in[i] - '0';
        ch = digit + 'A' - 1;
        out[j] = ch;
        generate_strings(in, out, i + 1, j + 1);
    }
    //taking 2 integers if it is smaller than 26
    if (in[i + 1] != '\0')
    {
        int seconddigit = in[i + 1] - '0';
        int no = digit * 10 + seconddigit;
        if (no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;
            generate_strings(in, out, i + 2, j + 1);
        }
    }
    return;
}

int main()
{
    char input[100]; //digits
    cin >> input;
    char output[100];
    generate_strings(input, output, 0, 0);
    return 0;
}