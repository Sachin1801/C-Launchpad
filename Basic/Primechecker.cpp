#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i;
    for (i = 2; i <= N - 1; i++)
    {
        if (N % i == 0)
        {
            cout << "Not Prime";
            break;
        }
    }
    if (i == N)
    {
        cout << "Prime";
    }
}
