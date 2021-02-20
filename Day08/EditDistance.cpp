#include <bits/stdc++.h>
using namespace std;

int editDistance(string a, string b) {
    int la = a.size(), lb = b.size();
    vector<vector<int>> dp(la+1, vector<int>(lb + 1, 0));
    for (int i = 0; i <= la; ++i) {
        for (int j = 0; j <= lb; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) 
                dp[i][j] = i;
            else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1  + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
}
int main() {

}