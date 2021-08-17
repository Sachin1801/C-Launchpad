#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int c = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = c; j > 0; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
        c--;
    }
}