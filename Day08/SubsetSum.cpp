#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& coins, int N) {
    int M = coins.size();
    vector<vector<bool>>dp(M+1, vector<bool>(N+1, false));

    for (int j = 0; j < M; j++) {
        dp[j][0] = true;
    }

    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            if (i < coins[j-1]) {
                // we cannot include this coin as the value of this coin is greater than the required value
                // exclude 
                dp[j][i] = dp[j-1][i];
            } else {
                dp[j][i] = dp[j-1][i] || dp[j-1][i - coins[j - 1]];
            }
        }
    }
    return dp[M][N];
}


bool subsetSumInfiniteCoins(vector<int>& coins, int N) {
    int M = coins.size();
    vector<vector<bool>>dp(M+1, vector<bool>(N+1, false));

    for (int j = 0; j < M; j++) {
        dp[j][0] = true;
    }

    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N; i++) {
            if (i < coins[j-1]) {
                // we cannot include this coin as the value of this coin is greater than the required value
                // exclude 
                dp[j][i] = dp[j-1][i];
            } else {
                dp[j][i] = dp[j-1][i] || dp[j][i - coins[j - 1]];
            }
        }
    }
    return dp[M][N];
}
int main() {
    return 0;
}