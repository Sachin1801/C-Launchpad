#include <iostream>
using namespace std;

int main()
{
    char ch;
    int N1, N2;
    cin >> ch;
    while (ch != 'x' && ch != 'X')
    {

        switch (ch)
        {
        case '+':
            cin >> N1 >> N2;
            cout << N1 + N2 << endl;
            break;
        case '-':
            cin >> N1 >> N2;
            cout << N1 - N2 << endl;
            break;
        case '*':
            cin >> N1 >> N2;
            cout << N1 * N2 << endl;
            break;
        case '/':
            cin >> N1 >> N2;
            cout << N1 / N2 << endl;
            break;
        default:
            cout << "Invalid operation. Try again." << endl;
            break;
        }
        cin >> ch;
    }
    return 0;
}
