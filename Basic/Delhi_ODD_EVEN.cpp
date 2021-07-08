#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int r, evensum = 0, oddsum = 0;
    long long int num;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;

        while (num > 0)
        {
            r = num % 10;
            if (r % 2 == 0)
            {
                evensum = evensum + r;
                num = num / 10;
            }
            else if (r % 2 == 1)
            {
                oddsum = oddsum + r;
                num = num / 10;
            }
        }
        if (oddsum % 3 == 0)
        {
            cout << "Yes" << endl;
        }
        else if (evensum % 4 == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}