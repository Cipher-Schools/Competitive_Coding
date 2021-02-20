#include <bits/stdc++.h>
using namespace std;

// When coins are infinite
int minCoins(vector<int> & coins, int N) {
    if (N == 0)
        return 0;
    int M = coins.size();
    // What is the min number of coins required to make n where 0 <= n <= N
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int n = 1; n <= N; n++) {
        for (int i = 0; i < M; i++) {
            if (coins[i] <= n ) {
                if (dp[n - coins[i]] == INT_MAX)
                    continue;
                dp[n] = min(dp[n], 1 + dp[n - coins[i]]);
            }
        }
    }

    if (dp[N] == INT_MAX)
        return -1;
    else 
        return dp[N];
    
}

// time complexity O(N*M)
int main() {

}