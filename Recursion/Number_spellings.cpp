#include <iostream>
using namespace std;

char words[][100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printspelling(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    //recursive case for (204)
    printspelling(n / 10);
    //after the function call
    int digit = n % 10;
    cout << words[digit] << " ";
}

int main()
{
    int n;
    cin >> n;
    printspelling(n);
    return 0;
}