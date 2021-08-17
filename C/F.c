#include <stdio.h>
#include <string.h>

void swapCBR(char *x, char *y)
{
    char t;

    t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    char str[100];

    scanf("%s", str);

    int n = strlen(str);

    int isPalin = 1;
    for (int i = 0; i < n / 2; i++)
    {
        swapCBR(&str[i], &str[n - i - 1]);
    }

    printf("Reversed String is %s", str);
}