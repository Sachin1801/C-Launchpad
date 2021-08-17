#include <iostream>
#include <cmath>
using namespace std;

bool canplace(int mat[][9], int i, int j, int n, int number)
{
    for (int x = 0; x < n; x++)
    {
        //Row and column check
        if (mat[x][j] == number || mat[i][x] == number)
        {
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;
    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (mat[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    //base case
    if (i == n)
    {
        //Print the solution
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    //Cse- Row End
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }
    //Skip the pre-filled cells
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }
    //recursive case
    //fill the current cells with the possible options
    for (int number = 1; number <= n; number++)
    {
        if (canplace(mat, i, j, n, number))
        {
            //Assuming the number is correct
            mat[i][j] = number;
            bool couldwesolve = solveSudoku(mat, i, j + 1, n);
            if (couldwesolve)
            {
                return true;
            }
        }
    }
    //backtracking
    mat[i][j] = 0;
    return false;
}

int main()
{
    int mat[9][9] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solveSudoku(mat, 0, 0, 9);

    return 0;
}