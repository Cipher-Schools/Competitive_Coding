#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> &matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

bool isSafe(vector<vector<bool>> &board, int row, int col, int N)
{
    int r, c;
    // check horizontally
    for (c = col; c >= 0; c--)
    {
        if (board[row][c])
        {
            cout << "visited at " << row << " " << c << endl;
            return false;
        }
    }

    // check vertically upward
    for (r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c])
        {
            return false;
        }
    }

    // check vertically downward
    for (r = row, c = col; r < N && c >= 0; r++, c--)
    {
        if (board[r][c])
        {
            return false;
        }
    }

    return true;
}

bool NQueenHelper(vector<vector<bool>> &board, int col, int N)
{
    if (col >= N)
    {
        return true;
    }

    for (int row = 0; row < N; row++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = true;
            if (NQueenHelper(board, col + 1, N))
            {
                return true;
            }
            board[row][col] = false;
        }
    }
    return false;
}

vector<vector<bool>> NQueen(int N)
{
    vector<vector<bool>> board(N, vector<bool>(N, false));
    NQueenHelper(board, 0, N);
    return board;
}

int main()
{
    int testCases = 1, N = 4;
    // cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        // cin >> N;
        vector<vector<bool>> board = NQueen(N);

        printMatrix(board, N, N);
        // your function
    }
}