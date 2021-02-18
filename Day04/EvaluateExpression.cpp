#include <bits/stdc++.h>
using namespace std;

int evaluateExpression(vector<string> &inputs)
{
    stack<int> S;
    for (int i = 0; i < inputs.size(); i++)
    {
        if (inputs[i] == "+" || inputs[i] == "-" || inputs[i] == "*" || inputs[i] == "/")
        {
            int v1 = S.top(); S.pop();
            int v2 = S.top(); S.pop();
            if (inputs[i] == "+")
                S.push(v2 + v1);
            else if (inputs[i] == "-")
                S.push(v2 - v1);
            else if (inputs[i] == "*")
                S.push(v2 * v1);
            else if (inputs[i] == "/")
                S.push(v2 / v1);
        }
        else
            S.push(stoi(inputs[i]));
    }
    return S.top();
}
int main()
{
}