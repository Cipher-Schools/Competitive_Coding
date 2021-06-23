#include <bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> &vec) {
    int water = 0;
    vector<int> left(vec.size(), 0), right(vec.size(), 0);

    left[0] = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        left[i] = max(left[i-1], vec[i]);
    }

    for (int i = vec.size() - 2; i >= 1; i--) {
        right[i] = max(right[i+1], vec[i]);
    }

    for (int i = 0; i < vec.size(); i++) {
        water += min(left[i], right[i]) - vec[i];
    }
    return water;
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