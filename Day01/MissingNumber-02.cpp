#include <bits/stdc++.h>
using namespace std;

// Bitwise operator
// | (or), & (and), ^ (xor), ~ (not), << (left shift), >> (right shift)
int missingNumber(vector<int> & vec) {
    int x0r = 0;
    for (int i = 0; i < vec.size(); i++) {
        x0r ^= vec[i];
        x0r ^= (i+1);
    }
    return x0r ^ (vec.size()+1);
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