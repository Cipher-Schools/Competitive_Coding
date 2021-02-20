#include <bits/stdc++.h>
using namespace std;


void medianOfRunningStream(vector<double>& vec) {
    int N = vec.size();
    priority_queue<double> maxHeap; 
    priority_queue<double, vector<double>, greater<double> > minHeap; 
    // Base case when vector has one element.
    maxHeap.push(vec[0]);
    cout << maxHeap.top() << " ";
    double top, top1, top2;
    for (int i = 1; i < vec.size(); i++) {
        maxHeap.push(vec[i]);
        while (maxHeap.size() - minHeap.size() > 1) {
            top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        } 
        if (maxHeap.size() > minHeap.size()) {
            cout << maxHeap.top() << " ";
        } else if (maxHeap.size() == minHeap.size()) {
            top1 = maxHeap.top();
            top2 = minHeap.top();
            cout << (top1 + top2)/2 << " ";
        } else {
            // This condition will never come.
        }
    }
}
int main() {

}