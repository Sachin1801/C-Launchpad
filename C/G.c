#include <stdio.h>
#include <string.h>

struct numbers
{
    int a, b;
    float c;
};

void copyStruct(struct numbers *first, struct numbers *second)
{

    first->a = second->a;
    first->b = second->b;
    first->c = second->c;
}

int main()
{
    struct numbers num;
    scanf("%d %d %f", &num.a, &num.b, &num.c);

    struct numbers copyNumbers;

    copyStruct(&copyNumbers, &num);

    printf("Copied Structure Object is -> a: %d, b: %d, c: %f\n", copyNumbers.a, copyNumbers.b, copyNumbers.c);
}