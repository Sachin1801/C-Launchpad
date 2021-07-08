#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int n;
    cin >> n;

    while (n > 0)
    {
        int last_digit = n % 10;
        sum = sum + last_digit;

        n = n / 10;
    }
    cout << "Sum of the digits is " << sum << endl;

    return 0;
}