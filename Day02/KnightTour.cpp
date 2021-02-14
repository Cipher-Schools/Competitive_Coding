#include <bits/stdc++.h>
using namespace std;

int BoardSize = 8;
int possibleMoves = 8;
int xMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(vector<vector<int>> &board, int r, int c)
{
    return (r >= 0 && r < BoardSize && c >= 0 && c < BoardSize && board[r][c] == 0);
}

bool knightTourHelper(vector<vector<int>> &board, int r, int c, int count)
{
    if (count == BoardSize * BoardSize)
    {
        return true;
    }

    for (int i = 0; i <= possibleMoves; i++)
    {
        int nextXMove = r + xMoves[i];
        int nextYMove = c + yMoves[i];
        if (isSafe(board, nextXMove, nextYMove))
        {
            board[nextXMove][nextYMove] = count;
            if (knightTourHelper(board, nextXMove, nextYMove, count + 1))
            {
                return true;
            }
            else
            {
                board[nextXMove][nextYMove] = 0;
            }
        }
    }

    return false;
}

bool knightTour()
{
    vector<vector<int>> board(BoardSize, vector<int>(BoardSize, 0));
    board[0][0] = 1;
    if (knightTourHelper(board, 0, 0, 2)) {
        cout << "Found it\n";
        for (vector<int> row : board) {
            for (int cell: row) {
                cout << cell << "\t";
            }
            cout << "\n";
        }
        return true;
    } else {
        cout << "No Path Found\n";
        return false;
    }

}
int main()
{
    knightTour();
}