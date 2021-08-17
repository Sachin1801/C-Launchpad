#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("Before Swap -> a: %d, b: %d\n", a, b);

    swap(&a, &b);

    printf("After Swap -> a: %d, b: %d", a, b);
}