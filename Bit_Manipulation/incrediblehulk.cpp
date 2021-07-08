#include <iostream>
using namespace std;

int setbits(int no)
{
    int ans = 0;
    while (no > 0)
    {
        no = no & (no - 1);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int no;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        cout << setbits(no) << endl;
    }
    return 0;
}