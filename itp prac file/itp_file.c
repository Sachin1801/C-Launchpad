//Insertion Sort
#include <stdio.h>

void printarr(int arr[], int len)
{
    int i;
    printf("Array is ->");
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insert(int arr[], int len)
{
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[10] = {10, 9, 2, 13, 1, 199, 20, -1, 0, -10};
    int len;
    len = sizeof(arr) / sizeof(int);
    insert(arr, len);
    printarr(arr, len);
    return 0;
}
