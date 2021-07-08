#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, min, max;
    cin >> n;
    int no;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        if (no < min)
        {
            min = no;
        }
        else if (no > max)
        {
            max = no;
        }
    }
    return 0;
}
