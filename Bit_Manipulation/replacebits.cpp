#include <iostream>
using namespace std;

int clearRangeItoJ(int n, int i, int j)
{
    int ones = (~0);
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int Replacebits(int n, int m, int i, int j)
{
    int n_ = clearRangeItoJ(n, i, j);
    int ans = n_ | (m << i);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int i = 1, j = 3;
    cout << Replacebits(n, m, i, j) << endl;
}