#include <bits/stdc++.h>
using namespace std;

int stocksBuySell(vector<int> & stockPrice) {
    int minVal = stockPrice[0], profit = 0;
    for (int i = 1;  i < stockPrice.size(); i++) {
        if (minVal <= stockPrice[i]) {
            int tempProfit = stockPrice[i] - minVal;
            profit = max(profit, tempProfit);
        } else {
            minVal = stockPrice[i];
        }
    }

    return profit;
}
int main() {
    return 0;
}