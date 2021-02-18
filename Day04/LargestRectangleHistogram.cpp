#include <bits/stdc++.h>
using namespace std;

// 1. if the current element is equal or greater than the top of stack
//    a. Add the element to the stack
// 2.  else
//    a. Keep removing elements from the stack till a number which is smaller than or equal to the current element
//    b. Calculate the area
//          i. if the stack is empty => area = heights[top] * i;
//          ii. else => area = heights[top] * (i - stackTop  - 1);
int largestRectangleArea(vector<int> &heights)
{
    int area = 0, maxArea = 0, tp = 0, i = 0, N = heights.size();
    stack<int> S;
    while  (i < N)
    {
        if (S.empty() || heights[S.top()] <= heights[i])
            S.push(i++);
        else
        {
            tp = S.top(); S.pop();
            if (S.empty())
                area = heights[tp] * i;
            else
                area = heights[tp] * (i - S.top() - 1);

            maxArea = max(maxArea, area);
        }
    }
    while (!S.empty())
    {
        tp = heights[S.top()]; S.pop();
        if (S.empty())
            area = heights[tp] * i;
        else
            area = heights[tp] * (i - S.top() - 1);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
}