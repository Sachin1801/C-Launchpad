#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float powr;
    float ans = 0;
    powr = pow(a, b);
    ans = powr % c;
    cout << ans << endl;
    return 0;
}