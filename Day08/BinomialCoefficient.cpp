#include <bits/stdc++.h>
using namespace std;

long BinomialCoefficient(long N, long R)
{
    vector<vector<long>> C(N + 1, vector<long>(R + 1, 0));

    for (long n = 0; n <= N; n++)
    {
        for (long r = 0; r <= min(n, R); r++)
        {
            if (n == 0 || r == 0)
            {
                // (n)C(0) || (0)C(0)
                C[n][r] = 1;
            }
            else
            {
                C[n][r] = C[n - 1][r] + C[n - 1][r - 1];
            }
        }
    }

    return C[N][R];
}
int main()
{
    return 0;
}