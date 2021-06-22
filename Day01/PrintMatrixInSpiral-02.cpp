#include <bits/stdc++.h>
using namespace std;

void printMatrixInSpiralHelper(const vector<vector<int>> &matrix, int r, int row, int c, int col)
{
    if (r > row || c > col)
        return;

    for (int j = c; j <= col; j++)
    {
        cout << matrix[r][j] << " ";
    }
    r++;

    for (int i = r; i <= row; i++)
    {
        cout << matrix[i][col] << " ";
    }
    col--;

    if (r <= row)
    {
        for (int j = col; j >= c; j--)
        {
            cout << matrix[row][j] << " ";
        }
        row--;
    }

    if (c <= col)
    {
        for (int i = row; i >= r; i--)
        {
            cout << matrix[i][c] << " ";
        }
        c++;
    }

    printMatrixInSpiralHelper(matrix, r, row, c, col);
}
void printMatrixInSpiral(const vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return;

    int row = matrix.size() - 1, col = matrix[0].size() - 1;
    printMatrixInSpiralHelper(matrix, 0, row, 0, col);
}

int main()
{
    int testCases, row, col;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> row >> col;
        vector<vector<int>> matrix(row, vector<int>(col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }

        printMatrixInSpiral(matrix);
        cout << "\n";
    }
}