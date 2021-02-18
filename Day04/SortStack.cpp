#include <bits/stdc++.h>
using namespace std;

void insertAtRightPlace(stack<int> &S, int temp)
{
    if (S.empty() || S.top() <= temp)
    {
        S.push(temp);
    }
    else
    {
        int temp1 = S.top();
        S.pop();
        insertAtRightPlace(S, temp);
        S.push(temp1);
    }
}

void reverseStack(stack<int> &S)
{
    if (!S.empty())
    {
        int temp = S.top();
        S.pop();
        reverseStack(S);
        insertAtRightPlace(S, temp);
    }
}
int main()
{
    stack<int> S;
    for (int i = 0; i < 5; i++)
        S.push(i + 1);
    reverseStack(S);
    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}