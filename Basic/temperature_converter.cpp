#include <iostream>
using namespace std;

int main()
{
    float c, f = 0;
    int min, max, step;
    cin >> min >> max >> step;

    while (min <= max)
    {
        c = ((5 * (min - 32)) / 9);
        cout << min << '\t' << c << endl;
        min = min + step;
    }

    return 0;
}