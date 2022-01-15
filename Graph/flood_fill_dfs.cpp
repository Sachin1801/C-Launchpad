#include <iostream>
using namespace std;

int R;
int C;

void print(char mat[][50])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << mat[i][j];
        }
    }
}

// West ,North ,east, south
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// ch is the character to be replaced
// colour is the character that we are adding
void FloodFill(char mat[][50], int i, int j, char ch, char color)
{
    // base case
    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return;
    }
    // figure boundary case
    if (mat[i][j] != ch)
    {
        return;
    }
    // recursive case
    mat[i][j] = color;
    for (int k = 0; k < 4; k++)
    {
        FloodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}

int main()
{
    cin >> R >> C;
    char input[15][50];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> input[i][j];
        }
    }

    print(input);

    FloodFill(input, 8, 13, '.', 'r');

    print(input);
    return 0;
}