#include <iostream>
#include <cstring>
using namespace std;

string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void smart_keypad(string in, string out)
{
    //base case
    if (in.size() == 0)
    {
        cout << out << endl;
        return;
    }
    //recursive case
    int digit = in[0] - '0';
    for (unsigned int k = 0; k < table[digit].length(); k++)
    {
        char ch = table[digit][k];
        //fill the remaining part
        smart_keypad(in.substr(1), out + ch);
    }
    return;
}

int main()
{
    string input;
    cin >> input;
    smart_keypad(input, "");
    return 0;
}