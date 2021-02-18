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

TreeNode * sortedArrayToBst(vector<int> vec, int start, int end) {
    if (end < start) {  
        return NULL;
    }
    if (start == end) {
        return new TreeNode(vec[start]);
    }
    
    int mid = start + (end - start)/2;
    TreeNode * newNode = new TreeNode(vec[mid]);
    newNode->left = sortedArrayToBst(vec, start, mid - 1);
    newNode->right = sortedArrayToBst(vec, mid + 1, end);
    return newNode; 
}