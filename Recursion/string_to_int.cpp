#include <iostream>
#include <cstring>
using namespace std;

int stringtoint(char *a, int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }
    // last digitā
    int digit = a[n - 1] - '0'; // end mai -'0' isliye kiya kyuki vo uski ascii value ko kat kar integer de deta hai

    int small_ans = stringtoint(a, n - 1);
    //final ans
    return small_ans * 10 + digit;
}

int main()
{
    //given a stirng convert it into integer respectively
    char a[100];
    cin >> a;
    int len = strlen(a);

    cout << stringtoint(a, len) << endl;
    cout << endl;

    return 0;
}