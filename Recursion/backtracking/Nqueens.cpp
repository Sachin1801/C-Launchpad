#include <iostream>
using namespace std;

bool issafe(int board[][10], int i, int j, int n)
{
    //You can check for column
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1) //changing the rwos and checking for the same column
        {
            return false;
        }
    }
    //You can check for the left diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    //check for right diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    //The position is now safe as we have chcked for the columns as well as diagonals
    return true;
}

bool solveNqueen(int board[][10], int i, int n)
{
    //base case
    if (i == n)
    {
        //it means that you have succesfully placed n queens from rows(0......n-1)
        //Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl
             << endl;
        return false; //we have written false here to get all the possible configurations
    }
    //recursive case
    //try to place the queen in the current row and call the remaining part which wiol be solved by recursion
    for (int j = 0; j < n; j++)
    {
        //I have to check if the i,j th position is safe to place the queen or not.
        if (issafe(board, i, j, n))
        {
            //Place the queen - assuming i , j is the right the position
            board[i][j] = 1;
            bool nextqueenrakhpaye = solveNqueen(board, i + 1, n);
            if (nextqueenrakhpaye)
            {
                return true;
            }
        }
        //if it has reached here means the assumption is wrong , we have to perform backtracking
        board[i][j] = 0; //backtracking
    }
    //you have tried for all positions for the current row but couldn't place the queen
    return false;
}

int main()
{
    int n;
    cin >> n;
    int board[10][10] = {0};
    solveNqueen(board, 0, n);
    return 0;
}