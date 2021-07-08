#include <iostream>
#include <vector>

using namespace std;

void Primefactors(int n)
{
    vector<pair<int, int>> factor;
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            //Keep on dividing it till it is divisible
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            factor.push_back(make_pair(i, cnt));
            cnt = 0;
        }
    }
    //condition for whatever is left is the prime number
    if (n != 1)
    {
        factor.push_back(make_pair(n, 1));
    }
    //Now printing the prime factors
    for (auto p : factor)
    {
        cout << p.first << "^" << p.second << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    Primefactors(n);

    return 0;
}