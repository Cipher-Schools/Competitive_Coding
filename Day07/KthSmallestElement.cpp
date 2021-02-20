#include <bits/stdc++.h>
using namespace std;


int kthSmallestElement(vector<int>& vec, int k) {
    // priority_queue<int, vector<int>, greater<int>> gq) PQ => Min Heap
    priority_queue<int> PQ; 
    for (int i = 0; i < vec.size(); i++) {
        // 0..k-1
        PQ.push(vec[i]);

        if (PQ.size() > k) {
            PQ.pop();
        }
    }
    return PQ.top();
}

int main() {
    vector<int> vec = {7, 10, 4, 3, 19, 2, 14, 16, 4};
    for (int i = 0; i < vec.size(); i++) {
        cout << kthSmallestElement(vec, i+1) << "\n";
    }
    
}