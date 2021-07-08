#include <iostream>
using namespace std;

bool isOdd(int n)
{
    return (n & 1);
}

int getbit(int n, int i)
{
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}

int setbit(int n, int i)
{
    int mask = (1 << i);
    int ans = n | mask;
    return ans;
}

void clearbit(int n, int i)
{
    int mask = ~(1 << i);
    int no = (n & mask);
    cout << "Number after clearing the bit " << no << endl;
}

void updatebit(int &n, int i, int v)
{
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);
}

int clearLastIbits(int n, int i)
{
    int mask = (-1 << i);
    return n & mask;
}

int clearRangeItoJ(int n, int i, int j)
{
    int ones = (~0);
    int a = ones << (j + 1);
    int b = (1 << i) - 1;
    int mask a | b;
    int n = n & mask;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int i;
    cin >> i;

    //cout << isOdd(n) << endl;
    //cout << getbit(n, i) << endl;
    //n = setbit(n, i);
    //cout << "ans " << n << endl;
    updatebit(n, 2, 0);
    updatebit(n, 3, 1);
    cout << n << endl;
    return 0;
}