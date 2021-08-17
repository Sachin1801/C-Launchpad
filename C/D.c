#include <stdio.h>
// Call by Value
void swapCBV(int x, int y)
{
    int t;

    t = x;
    x = y;
    y = t;
}
// Call By Reference
void swapCBR(int *x, int *y)
{
    int t;

    t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("Before Swap ( Call By Value ) -> a: %d, b: %d\n", a, b);

    swapCBV(a, b);

    printf("After Swap ( Call By Value ) -> a: %d, b: %d\n\n", a, b);

    printf("Before Swap ( Call By Reference ) -> a: %d, b: %d\n", a, b);

    swapCBR(&a, &b);

    printf("After Swap ( Call By Reference ) -> a: %d, b: %d\n", a, b);

    return 0;
}