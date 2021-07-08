#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 1;
    int b = 1;

    if (n == 1)
    {
        cout << "0" << endl;
    }
    else if (n == 2)
    {
        cout << "0" << endl;
        cout << "1\t1" << endl;
    }
    else
    {
        cout << "0" << endl;
        cout << "1\t1" << endl;
        for (int i = 2; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << a + b << "\t";
                int c = a + b;
                a = b;
                b = c;
            }
            cout << endl;
        }
    }
}
