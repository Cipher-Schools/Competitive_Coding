#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> & vec) {
    int N_1  = vec.size();
    long long sum = 0;
    for (int i = 0; i < N_1; ++i) {
        sum += ((i+1) - vec[i]);
    }
    return sum + (N_1 + 1);
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
        
        cout << missingNumber(vec) << endl;
    }
}