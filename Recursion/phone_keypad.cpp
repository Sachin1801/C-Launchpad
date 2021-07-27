#include <iostream>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *in, char *out, int i, int j)
{
    //base case
    if (in[i] == '\0')
    {
        out[i] = '\0';
        cout << out << endl;
        return;
    }
    //rec case
    int digit = in[i] - '0'; // This is done to subtract the ascii values of the number in the input array with 0 (ascii- 50) to get the number that we want
    if (digit == 1 || digit == 0)
    {
        generate_names(in, out, i + 1, j);
    }
    for (int k = 0; keypad[digit][k] != 0; k++)
    {
        out[j] = keypad[digit][k];
        //fill the remaining part
        generate_names(in, out, i + 1, j + 1);
    }
    return;
}

int main()
{
    char input[100];
    cin >> input;
    char output[100];
    generate_names(input, output, 0, 0);
    return 0;
}