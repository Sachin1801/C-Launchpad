#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int root1, root2;
    int sqrtn;
    sqrtn = sqrt((b * b) - (4 * a * c));
    if (sqrtn > 0)
    {

        root1 = ((b * (-1)) + sqrtn) / (2 * a);
        root2 = ((b * (-1)) - sqrtn) / (2 * a);
        cout << "Real and Distinct" << endl;
        cout << root2 << " " << root1;
    }
    else if (sqrtn == 0)
    {
        cout << "Real and Equal" << endl;
        cout << ((-1) * b) / (2 * a) << " " << ((-1) * b) / (2 * a);
    }
    else
    {
        cout << "Imaginary";
    }
}
