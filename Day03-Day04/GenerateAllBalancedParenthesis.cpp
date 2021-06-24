#include <bits/stdc++.h>
using namespace std;

void generateAllBalancedParenthesesHelper(int open, int close, string &resultSoFar, vector<string> &parentheses) {
    if (open < 0 || close < 0) {
        return;
    }

    if (open > close) {
        return;
    } else {
        // open <= close
         if (open == 0 && close == 0) {
            parentheses.push_back(resultSoFar);
            return;
        }

        resultSoFar.push_back('(');
        generateAllBalancedParenthesesHelper(open - 1, close, resultSoFar, parentheses);
        resultSoFar.pop_back();

        resultSoFar.push_back(')');
        generateAllBalancedParenthesesHelper(open, close - 1, resultSoFar, parentheses);
        resultSoFar.pop_back();
    }
}

vector<string> generateAllBalancedParentheses(int n) {
    vector<string> parentheses;
    string resultSoFar = "";
    generateAllBalancedParenthesesHelper(n, n, resultSoFar, parentheses);
    return parentheses;
}

int main() {
    int testCases, n;
    cin >> testCases;
    while (testCases > 0)
    {
        testCases--;
        cin >> n;        
        vector<string> parentheses = generateAllBalancedParentheses(n);
        for (int i = 0; i < parentheses.size(); i++) {
            cout << parentheses[i] << " ";
        }
        cout << endl;
        // your function
    }
}