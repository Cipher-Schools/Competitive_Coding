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

int largestSumSubtree(TreeNode * root, int &resSoFar) {
    if (root == NULL) {
        return 0;
    } 
    int l = largestSumSubtree(root->left, resSoFar);
    int r = largestSumSubtree(root->right, resSoFar);

    int curr = (root->data + l + r); 
    resSoFar = max(resSoFar, curr);
    return curr;
}

int largestSumSubtree(TreeNode * root) {
    int resSoFar = INT_MIN;
    int res = largestSumSubtree(root, resSoFar);
    return resSoFar;
}