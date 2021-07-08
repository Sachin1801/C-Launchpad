#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100000];
    int no;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        a[i] = no;
        res = res ^ no;
    }
    //res=a^b
    int temp = res;
    int pos = 0;
    while ((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }
    //The fisrt bit in xor is at position 'pos'
    int mask = (1 << pos);

    //Find those numbers which contain set bit at position 'pos'
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & mask) > 0)
            a
            {
                x = x ^ a[i];
            }
    }
    y = res ^ x;

    cout << min(x, y) << " " << max(x, y);
    return 0;
}