#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> row, int start, int end, int x) {
    return 0;
}

// Homework 
// itr = binary_search(matrix[i].begin(), matrix[i].end(), x)
// if (itr == matrix[i].end()) => We did not find the element
// other we did 
pair<int, int> findElement(vector<vector<int>> matrix, int x) {
    for (int i = 0; i < matrix.size(); i++) {
        int j = binarySearch(matrix[i], 0, matrix[i].size() - 1, x);
        if (j >= 0) {
            return pair<int, int>{i, j};
        }
    }
} 

// O(mlogn)

int main() {
    return 0;
}