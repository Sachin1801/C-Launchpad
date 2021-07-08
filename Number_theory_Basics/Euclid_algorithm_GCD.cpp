#include <iostream>
using namespace std;

void GCD(int a, int b)
{

    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    cout << a << endl;
}

int main()
{
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0)
    {
        GCD(max(x, y), min(x, y));
    }
    else
    {
        cout << "Invalid input" << endl;
    }
    return 0;
}