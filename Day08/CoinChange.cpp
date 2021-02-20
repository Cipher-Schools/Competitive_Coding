#include <bits/stdc++.h>
using namespace std;

int CoinChange(int Sum, vector<int> Coins)
{
    int CoinsCount = Coins.size();
    vector<vector<int>> dp(Sum + 1, vector<int>(CoinsCount, 0));

    for (int c = 0; c < CoinsCount; c++)
    {
        dp[0][c] = 1;
    }

    for (int s = 1; s <= Sum; s++)
    {
        for (int c = 0; c < CoinsCount; c++)
        {
            if (s >= Coins[c])
            {
                dp[s][c] += dp[s - Coins[c]][c];
            }

            if (c >= 1)
            {
                dp[s][c] += dp[s][c - 1];
            }
        }
    }

    return dp[Sum][CoinsCount - 1];
}

int main()
{
    vector<int> Coins = {1, 2, 3};
    cout << CoinChange(4, Coins);
    return 0;
}