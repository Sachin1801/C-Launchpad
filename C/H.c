#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        char c = 'A';

        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (j >= i && j < 2 * n - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("%c", c);
            }
            if (j < n - 1)
            {
                c++;
            }
            else
            {
                c--;
            }
        }

        printf("\n");
    }
}