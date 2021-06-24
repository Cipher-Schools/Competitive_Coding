#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> &matrix, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << '\n';
    }
}

#define POSSIBLE_MOVES 8
int xMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(const vector<vector<int>> &board, int x, int y, const int &N)
{
    if (x < 0 || x >= N || y < 0 || y >= N || board[x][y] != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool knightTourHelper(vector<vector<int>> &board, int x, int y, const int &N, int count)
{
    if (count == N * N + 1)
    {
        return true;
    }

    if (isSafe(board, x, y, N))
    {
        board[x][y] = count;

        int nextX, nextY;
        for (int i = 0; i < POSSIBLE_MOVES; i++)
        {
            nextX = x + xMoves[i];
            nextY = y + yMoves[i];
            if (knightTourHelper(board, nextX, nextY, N, count + 1))
            {
                return true;
            }
        }

        board[x][y] = 0;
    }
    return false;
}

vector<vector<int>> knightTour(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (knightTourHelper(board, 0, 0, N, 1)) {
        return board;
    } else {
        return {};
    }
    
}

int main()
{
    int testCases, N;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> N;
        vector<vector<int>> board = knightTour(N);

        printMatrix(board, N, N);
        cout << "\n";
        // your function
    }
}