#include <iostream>
#include <unordered_map>
using namespace std;

int rightangled(int arr[][2], int N)
{
    unordered_map<int, int> hx;
    unordered_map<int, int> hy;
    for (int i = 0; i < N; i++)
    {
        hx[arr[i][0]]++;
        hy[arr[i][1]]++;
    }
    // counting the number of right angled triangles
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (hx[arr[i][0]] >= 1 and hy[arr[i][1]] >= 1)
        {
            // Add the count of triangles formed
            cnt += (hx[arr[i][0]] - 1) * (hy[arr[i][1]] - 1);
        }
    }
    return cnt;
}

int main()
{
    int N = 5;
    int arr[][2] = {{2, 3}, {2, 5}, {2, 7}, {5, 3}, {7, 3}};
    cout << rightangled(arr, N);
    return 0;
}