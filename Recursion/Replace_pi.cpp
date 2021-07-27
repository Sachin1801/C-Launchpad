#include <iostream>
using namespace std;

void replacepi(char *a, int i)
{
    //base case
    if (a[i] == '\0' or a[i + 1] == '\0')
    {
        return;
    }
    //look for pi in the current location
    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        //shiftinf followed by the value 3.14
        int j = i + 2;
        //shifting j to the end
        while (a[j] != '\0')
        {
            j++;
        }
        //shifting right to left
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        //replacement of recursive call
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replacepi(a, i + 4);
    }
    else
    {
        //rec case
        replacepi(a, i + 1);
    }
    return;
}

int main()
{
    char a[10000];
    cin >> a;
    replacepi(a, 0);
    cout << a << endl;
    return 0;
}