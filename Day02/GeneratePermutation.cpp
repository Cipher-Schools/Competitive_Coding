#include <bits/stdc++.h>
using namespace std;

void generatePermutationHelper(string str, int start, int end, vector<string>& result) {
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
    vector<string> result = generatePermutation("ABC");
    for (string str : result) {
        cout << str << " ";
    }
}