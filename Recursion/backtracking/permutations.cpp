#include <iostream>
#include <string>
#include <set>
using namespace std;

void permutate(char *in, int i, set<string> &s)
{
    //base case
    if (in[i] == '\0')
    {
        //cout << in << ",";
        string t(a);
        s.insert(t);
        return;
    }
    //Recursive case
    for (int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permutate(in, i + 1, s);
        //backtracking
        swap(in[i], in[j]);
    }
}

int main()
{
    char in[100];
    cin >> in;
    set string<s>;

    permutate(in, 0, s);
    for (auto str : s)
    {
        cout << str << ",";
    }
    return 0;
}