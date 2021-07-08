#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int n;
    while (N > 0)
    {
        cin >> n;
        cout << n * n;
        N--;
        cout << endl;
    }
    return 0;
}