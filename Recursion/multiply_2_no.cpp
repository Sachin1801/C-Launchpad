#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    int ans = a + multiply(a, b - 1);
    return ans;
}

int main()
{
    //a and b are two numbers to be multiplied
    int a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}