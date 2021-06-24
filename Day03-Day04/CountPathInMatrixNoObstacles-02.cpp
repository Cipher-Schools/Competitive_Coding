#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    int C[n + 1][r + 1];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][r];
}

int countPathInMatrixNoObstacles(int m, int n)
{
    return nCr(m + n - 2, m - 1);
}

int main()
{
    int testCases, m, n;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> m >> n;
        cout << countPathInMatrixNoObstacles(m, n) << "\n";
    }
}