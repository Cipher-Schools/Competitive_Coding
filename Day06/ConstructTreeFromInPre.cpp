#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }

    TreeNode() {
        // constructor chaining
        TreeNode(0);
    }
};

int searching(vector<int> vec, int start, int end, int x) {
    for (int i = start; i < end; i++) {
        if (vec[i] == x) {
            return i;
        }
    }
    return -1; 
}

int index = 0;
TreeNode * construct(vector<int>& pre, vector<int>& in, int start, int end) {
    if (start > end) return NULL;
    TreeNode * newNode = new TreeNode(pre[index]);
    index ++;
    if (start == end) {
        return newNode;
    } else {
        int i = searching(in, start, end, newNode->data);
        newNode->left = construct(pre, in, start, i-1);
        newNode->right = construct(pre, in, i+1, end);
        return newNode;
    }
}