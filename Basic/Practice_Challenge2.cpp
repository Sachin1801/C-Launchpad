#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        int N;
        cin >> N;
        while (sum >= 0)
        {
            sum = sum + N;
            if (sum >= 0)
            {
                cout << N << endl;
            }
            cin >> N;
        }
        if (sum <= 0)
        {
            break;
        }
    }
    return 0;
}