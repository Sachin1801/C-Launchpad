#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];

    scanf("%s", str);

    int n = strlen(str);

    int isPalin = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            isPalin = 0;
            break;
        }
    }

    if (isPalin)
    {
        printf("Given string is a Palindrome!!\n");
    }
    else
    {
        printf("Given string is not a Palindrome!!\n");
    }
}