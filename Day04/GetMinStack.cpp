#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int getMin;
void push(int temp) {
    if (S.empty()) {
        S.push(temp);
        getMin = temp;
    } else {
        // 1. insert x
        // a. x >= getMin => Push(x)  
        // b. x < getMin => Push(2*x - getMin)
        if (temp >= getMin)
            S.push(temp);
        else {
            S.push(2*temp - getMin);
            getMin = temp;
        }
    }
}

void pop() {
    if (S.empty()) {
        return;
    } else {
        // 2. remove()
        // a. y >= getMin => remove(y);
        // b. y < getMin => getMin = (2*getMin - y);
        int y = S.top();
        if (y >= getMin) 
            S.pop();
        else {
            getMin = (2*getMin - y);
            S.pop();
        }
    }
}

int getMinimum() {
    return getMin;
}

int main() {

}
