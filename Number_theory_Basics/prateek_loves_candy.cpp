#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void primesieve(int *p)
{
    p[2] = 1;
    p[1] = p[0] = 0;
    //Marking the number as 1 means it is initially marked as prime
    //Marking all the odd numbers as prime first
    for (int i = 3; i <= 1000005; i = i + 2)
    {
        p[i] = 1;
    }

    v.push_back(2);

    //Sieve
    for (long long i = 3; i <= 1000005; i += 2)
    {
        //checking if it is marked or not as prime
        if (p[i] == 1)
        {
            v.push_back(i);
            for (long long j = i * i; j <= 1000005; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    int n;
    int p[1000005] = {0};
    primesieve(p);
    for (int j = 0; j < t; j++)
    {
        int in;
        cin >> in;
        cout << v[in - 1] << endl;
    }
}