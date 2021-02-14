#include <bits/stdc++.h>
using namespace std;

void balancedParenthesisHelper(vector<string>& result, int open, int close, int N, string str) {
    // open = 0, open = N, close = [0, N]
    if (open < 0 || close < 0 || open > N || close > N || close > open) {
        return;
    }
    if (open == N && close == N) {
        result.push_back(str);
        return;
    }

    balancedParenthesisHelper(result, open + 1, close, N, str + "(");
    balancedParenthesisHelper(result, open, close + 1, N, str + ")");
}

vector<string> balancedParenthesis(int N) {
    vector<string> result;
    balancedParenthesisHelper(result, 0, 0, N, "");
    return result;
}
int main() {
    vector<string> result = balancedParenthesis(5);
    for (string res : result) {
        cout << res << "\n";
    }
    return 0;
}