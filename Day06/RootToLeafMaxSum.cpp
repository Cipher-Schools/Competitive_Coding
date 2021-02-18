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

bool isLeaf(TreeNode * root) {
    return (root->left == NULL && root->right == NULL);
}

int maxSum = INT_MIN;
void sumRootToLeaf(TreeNode * root, int data) {
    if (root == NULL) {
        return;
    }
    data += root->data;
    if (isLeaf(root)) {
        maxSum = max(maxSum, data);
        cout << "\n";
    } else {
        sumRootToLeaf(root->left, data);
        sumRootToLeaf(root->right, data);
    }
}