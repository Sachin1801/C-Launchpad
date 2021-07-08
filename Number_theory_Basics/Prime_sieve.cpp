#include <iostream>
using namespace std;

void primesieve(int *p)
{
    p[2] = 1;
    p[1] = p[0] = 0;
    //Marking the number as 1 means it is initially marked as prime
    //Marking all the odd numbers as prime first
    for (int i = 3; i <= 1000000; i = i + 2)
    {
        p[i] = 1;
    }

    //Sieve
    for (long long i = 3; i <= 1000000; i += 2)
    {
        //checking if it is marked or not as prime
        if (p[i] == 1)
        {
            for (long long j = i * i; j <= 1000000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
}
int main()
{
    long long n;
    cin >> n;
    int p[1000005] = {0};
    primesieve(p);
    for (long long i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }
    return 0;
}