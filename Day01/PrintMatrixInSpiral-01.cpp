#include <bits/stdc++.h>
using namespace std;

void printMatrixInSpiral(const vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
    {
        return;
    }

    int r = 0, c = 0, row = matrix.size() - 1, col = matrix[0].size() - 1;
    while (r <= row && c <= col)
    {
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
    }
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