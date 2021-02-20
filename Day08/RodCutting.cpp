#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &Prices)
{
    int L = Prices.size();
    vector<int> dp(L, 0);
    for (int l = 0; l < L; l++)
    {
        dp[l] = Prices[l];
        for (int j = 0; j < l; j++)
        {
            dp[l] = max(dp[l], dp[j] + dp[l - j - 1]);
        }
    }
    return dp[L - 1];
}
int main()
{
}