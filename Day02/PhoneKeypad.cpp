#include <bits/stdc++.h>
using namespace std;

vector<string> keypad ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
// "23", 0
void generatePossibleCombinationsHelper(string digits, vector<string>& result, int index, string resSoFar) {
    if (index == digits.size()) {
        result.push_back(resSoFar);
        return;
    } 

    string possibleMoves = keypad[digits[index] - '0']; // 2 -> "abc" '2'-> int 2
    for (int i = 0; i < possibleMoves.size(); i++) {
        resSoFar.push_back(possibleMoves[i]);
        // resSoFar += possibleMoves[i];
        generatePossibleCombinationsHelper(digits, result, index + 1, resSoFar);
        // backtracking
        resSoFar.pop_back();
        // resSoFar = resSoFar.substring(0,)
    }

}
vector<string> generatePossibleCombinations(string digits) {
    if (digits.empty()) {
        return vector<string>{};
    }
    vector<string> result;
    generatePossibleCombinationsHelper(digits, result, 0, "");
    return result;
}

int main() {
    return 0;
}