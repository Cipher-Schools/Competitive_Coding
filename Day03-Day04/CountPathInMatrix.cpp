#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> &matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

// (x, y) => (x, y+1), (x+1, y)
// 0-> allowed, 1 -> obstacle
int countPathInMatrix(vector<vector<bool>> &matrix) {
    int row = matrix.size();
    if (row == 0) {
        return 0;
    }
    int col = matrix[0].size();
    if (matrix[0][0]) {
        return 0;
    }

    vector<vector<int>> dp(row, vector<int>(col, 0));

    dp[0][0] = 1;
    for (int i = 1; i < row; i++) {
        if (!matrix[i][0]) {
            dp[i][0] = dp[i-1][0];
        } else {
            break;
        }
    }
    for (int j = 1; j < col; j++) {
        if (!matrix[0][j]) {
            dp[0][j] = dp[0][j-1];
        } else {
            break;
        }
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (!matrix[i][j]) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = 0;
            }
            
        }
    }

    // printMatrix(dp, row, col);
    return dp[row-1][col-1];
}

int main() {
    int testCases, m, n;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> m >> n;
        vector<vector<bool>> matrix(m, vector<bool>(n));
        bool val;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                cin >> val;
                matrix[i][j] = val; 
            }
        }

        // printMatrix(matrix, m, n);
        
        // your function
        cout << countPathInMatrix(matrix) << "\n";
    }
}