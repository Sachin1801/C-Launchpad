#include <iostream>
using namespace std;

int main()
{

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            cout << " ";
        }
        int value = i;
        for (int k = 1; k <= i; k++)
        {
            cout << value;
            value++;
        }

        value = value - 2;
        for (int k = 1; k <= i - 1; k++)
        {
            cout << value;
            value--;
        }
        cout << endl;
    }
    return 0;
}