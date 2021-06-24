#include <bits/stdc++.h>
using namespace std;

void generatePermutationHelper(string &str, int start, int end, vector<string>& result) {
    if (start >= end) {
        result.push_back(str);
    } else {
        for (int i = start; i <= end; i++) {
            swap(str[i], str[start]);
            generatePermutationHelper(str, start+1, end, result);
            swap(str[i], str[start]);
        }
    }
}

vector<string> generatePermutation(string str) {
    vector<string> result;
    generatePermutationHelper(str, 0, str.size() - 1, result); 
    return result;
}

int main() {
     int testCases;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        string number;
        cin >> number;
        vector<string> permutations = generatePermutation(number);
        for (string permutation : permutations)
        {
            cout << permutation << " ";
        }
        cout << endl;
        // your function
    }
}