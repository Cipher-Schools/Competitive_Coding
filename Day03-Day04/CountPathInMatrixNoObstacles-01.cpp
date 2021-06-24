#include <bits/stdc++.h>
using namespace std;

int countPathInMatrixNoObstacles(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int testCases, m, n;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> m >> n;
        // vector<int> vec(vecSize);
        // for (int i = 0; i < vec.size(); i++)
        // {
        //     cin >> vec[i];
        // }
        
        // your function
        cout << countPathInMatrixNoObstacles(m, n) << "\n";
    }
}