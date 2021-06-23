#include <bits/stdc++.h>
using namespace std;

int largestSumContiguousSubarray(vector<int> &vec) {
    if (vec.size() == 0) return 0;

    int maxSofar = vec[0], currMax = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        currMax = max(currMax, currMax + vec[i]);
        maxSofar = max(maxSofar, currMax);
    }   

    return maxSofar;
}
int main() {
    int testCases, vecSize;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> vecSize;
        vector<int> vec(vecSize);
        for (int i = 0; i < vec.size(); i++)
        {
            cin >> vec[i];
        }
        
        // your function
    }
}