#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int c = i;
        for (int j = 0; j < (2 * n) - 1; j++)
        {

            if (j >= n - i && j < n + i - 1)
            {
                cout << c << "\t";
            }
            else
            {
                cout << " "
                     << "\t";
            }

            // updating the output
            if (j >= n - i)
            {
                if (j < n - 1)
                {
                    c++;
                }
                else
                {
                    c--;
                }
            }
        }
        cout << endl;
    }
}
