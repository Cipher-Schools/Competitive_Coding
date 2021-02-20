#include <bits/stdc++.h>
using namespace std;

int LongestSumIncreasingSubsequence(vector<int> &vec)
{
    vector<int> lis(vec.size(), 1);
    int maxLis = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        maxLis = max(maxLis, lis[i]);
    }

    return maxLis;
}

int main()
{
    vector<int> vec = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << LongestSumIncreasingSubsequence(vec);
    return 0;
}