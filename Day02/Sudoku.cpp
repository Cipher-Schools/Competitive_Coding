#include <bits/stdc++.h>
using namespace std;
#define N 9

bool usedInRow(vector<vector<int>> &grid, int row, int num)
{
    for (int i = 0; i < N; ++i)
    {
        if (grid[row][i] == num)
        {
            return true;
        }
    }
    return false;
}

bool usedInCol(vector<vector<int>> &grid, int col, int num)
{
    for (int i = 0; i < N; ++i)
    {
        if (grid[i][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool usedInBox(vector<vector<int>> &grid, int row, int col, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[row + i][col + j] == num)
            {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(vector<vector<int>> &grid, int row, int col, int num)
{
    return (!usedInRow(grid, row, num) &&
            !usedInCol(grid, col, num) &&
            !usedInBox(grid, row - row % 3, col - col % 3, num));
}

bool unassigned(vector<vector<int>> &grid, int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(vector<vector<int>> &grid)
{
    int row, col;
    if (!unassigned(grid, row, col))
    {
        return true;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solveSudoku(grid))
            {
                return true;
            }
            // backtracking
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(grid) == true)
        for (vector<int> row : grid)
        {
            for (int cell : row)
            {
                cout << cell << "\t";
            }
            cout << "\n";
        }
    else
        cout << "No solution exists";

    return 0;
}