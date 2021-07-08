#include <iostream>
using namespace std;

int storeocc(int *a, int i, int n, int key, int *out, int j)
{
    if (i == n)
    {
        return j;
    }
    if (a[i] == key)
    {
        out[j] = i;
        return storeocc(a, i + 1, n, key, out, j + 1);
    }
    return storeocc(a, i + 1, n, key, out, j + 1);
}

void allocc(int *a, int i, int n, int key)
{
    // base case
    if (i == n)
    {
        return;
    }
    if (a[i] == key)
    {
        cout << i << ",";
    }
    allocc(a, i + 1, n, key);
}

int lastocc(int *a, int n, int key)
{
    //base case
    if (n == 0)
    {
        return -1;
    }
    //recursive case
    int i = lastocc(a + 1, n - 1, key);
    if (i == -1)
    {
        if (a[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    //if i returned by subproblem is not -1
    return i + 1;
}

int firstocc(int *a, int n, int key)
{
    //base case
    if (n == 0)
    {
        return -1;
    }
    //primary check
    if (a[0] == key)
    {
        return 0;
    }
    //recursive cases
    int i = firstocc(a + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    return i + 1;
}

//different methord of doing the same question

int linearsearch2(int *a, int i, int n, int key)
{
    //base case
    if (i == n)
    {
        return -1;
    }

    if (a[i] == key)
    {
        return i;
    }
    return linearsearch2(a, i + 1, n, key);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 7, 9, 7, 10};
    int key;
    cin >> key;
    int n = sizeof(a) / sizeof(int);
    cout << firstocc(a, n, key) << endl;
    cout << linearsearch2(a, 0, n, key) << endl;
    cout << lastocc(a, n, key) << endl;
    allocc(a, 0, n, key);
    int output[100];
    int cnt = storeocc(a, 0, n, key, output, 0);
    cout << "Count is " << cnt << endl;
    for (int k = 0; k < cnt; k++)
    {
        cout << output[k] << " ";
    }
    return 0;
}