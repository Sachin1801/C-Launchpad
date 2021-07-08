#include <iostream>
#include <cstring>
using namespace std;

bool isPossible(int arr[], int n, int m, int current_min)
{
    int studentused = 1;
    int pages_reading = 0;
    for (int i = 0; i < n; i++)
    {
        if (pages_reading + arr[i] > current_min)
        {
            studentused++;
            pages_reading = arr[i];
            if (studentused > m)
            {
                return false;
            }
        }
        else
        {
            pages_reading += arr[i];
        }
    }
    return true;
}
//N=number of books
//M=number of students
int Findpage(int a[], int n, int m)
{
    int ans = -1;
    //If n<m
    if (n < m)
    {
        return ans;
    }
    else
    {
        int s = a[n - 1];
        int e = 0;
        //Count the max no. of pages for the maximum search limit
        for (int i = 0; i < n; i++)
        {
            e += a[i];
        }
        int ans = INT_MAX;
        while (s <= e)
        {
            int mid = (s + e) >> 1;

            if (isPossible(a, n, m, mid))
            {
                ans = min(ans, mid);
                //to find if an answer minimum than this is possible
                e = mid - 1;
            }
            else
            {
                //if it is not possible to divide the pages
                // so we need to increase the no.of pages
                s = mid + 1;
            }
        }
        return ans;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        int arr[1000];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        cout << Findpage(arr, n, m) << endl;
    }
    return 0;
}