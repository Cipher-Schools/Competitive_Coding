#include <bits/stdc++.h>
using namespace std;

int LongestCommonSubsequece(const string &a, const string &b)
{
    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }
            else
            {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
    }

    return lcs[a.size()][b.size()];
}
int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout << LongestCommonSubsequece(a, b);
    return 0;
}