#include <bits/stdc++.h>
using namespace std;
#define N 9

template <typename T>
void printMatrix(vector<vector<T>> &matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

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

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        vector<vector<int>> matrix(N, vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> matrix[i][j];
            }
        }

        printMatrix(matrix, N, N);
        cout << "\n";

        if (solveSudoku(matrix) == true)
        {
            printMatrix(matrix, N, N);
        }
        else
            cout << "No solution exists";
    }
}