#include <bits/stdc++.h>
using namespace std;

const int POSSIBLE_MOVES = 4;
vector<int> xMoves = {0, 1, 0, -1};
vector<int> yMoves = {1, 0, -1, 0};

bool isSafe(const vector<vector<bool>> &matrix, const vector<vector<bool>> &visited, int x, int y, int row, int col)
{
    // if the cell (x, y) is
    // 1. outside the matrix
    // 2. already visited
    // 3. has an obstacle
    // then it's not safe to visit that cell
    if (x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || matrix[x][y])
    {
        return false;
    }
    else
    {
        return true;
    }
}

// 0-> allowed, 1->obstacle
void countPathInMatrixAllDirectionMovementHelper(const vector<vector<bool>> &matrix, vector<vector<bool>> &visited, int x, int y, int row, int col, int &res)
{
    if (x == row - 1 && y == col - 1)
    {
        // we've reached our destination;
        visited[x][y] = true;
        res++;
    }
    
    if (isSafe(matrix, visited, x, y, row, col)) {
        visited[x][y] = true;
        int nextX, nextY;
        for (int i = 0; i < POSSIBLE_MOVES; i++) {
            nextX = x + xMoves[i];
            nextY = y + yMoves[i];
            countPathInMatrixAllDirectionMovementHelper(matrix, visited, nextX, nextY, row, col, res);
        }
        visited[x][y] = false;
    }
}

int countPathInMatrixAllDirectionMovement(const vector<vector<bool>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return 0;
    int col = matrix[0].size();
    if (matrix[0][0])
    {
        return 0;
    }
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int res = 0;
    countPathInMatrixAllDirectionMovementHelper(matrix, visited, 0, 0, row, col, res);
    return res;
}
int main()
{
    int testCases, row, col;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> row >> col;
        vector<vector<bool>> matrix(row, vector<bool>(col));
        bool val;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> val;
                matrix[i][j] = val;
            }
        }


        // your function
        cout << countPathInMatrixAllDirectionMovement(matrix) << "\n";
    }
}