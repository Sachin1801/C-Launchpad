#include <iostream>
using namespace std;

void counting_sort(int *arr, int n)
{
    //first we find the largest number in the array
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
    }
    //create a frequency array
    int *freq = new int[largest + 1]{0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    //put the elements back into the array by a reading freq array
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr) / sizeof(int);
    counting_sort(arr, n);

    return 0;
}