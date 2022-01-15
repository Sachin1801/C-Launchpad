#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string in, string out)
{
    if (in > out)
    {
        return true;
    }
    return false;
}

void dictionarylarger(string in, string out, int i, vector<string> &v)
{
    //base case
    if (i == in.length())
    {
        if (check(in, out))
        {
            v.push_back(in);
            return;
        }
        return;
    }
    //recursive case
    for (int j = i; j < in.length(); j++)
    {
        swap(in[i], in[j]);
        dictionarylarger(in, out, i + 1, v);
        //backtracking
        swap(in[i], in[j]);
    }
}
int main()
{
    string str;
    cin >> str;
    vector<string> v;
    dictionarylarger(str, str, 0, v);
    sort(v.begin(), v.end());
    for (auto val : v) //vector<int>::iterator == auto (in this case)
    {
        cout << val << endl;
    }
    return 0;
}