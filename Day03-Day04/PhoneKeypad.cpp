#include <bits/stdc++.h>
using namespace std;

vector<string> keypad ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
// "23", 0
void generatePossibleCombinationsHelper(string number, vector<string>& result, int index, string resSoFar) {
    if (index == number.size()) {
        result.push_back(resSoFar);
        return;
    } 

    string possibleMoves = keypad[number[index] - '0']; // 2 -> "abc" '2'-> int 2
    for (int i = 0; i < possibleMoves.size(); i++) {
        resSoFar.push_back(possibleMoves[i]);
        // resSoFar += possibleMoves[i];
        generatePossibleCombinationsHelper(number, result, index + 1, resSoFar);
        // backtracking
        resSoFar.pop_back();
        // resSoFar = resSoFar.substring(0,)
    }

}
vector<string> generatePossibleCombinations(string number) {
    if (number.empty()) {
        return vector<string>{};
    }
    vector<string> result;
    generatePossibleCombinationsHelper(number, result, 0, "");
    return result;
}

int main() {

}