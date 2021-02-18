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

// return diameter
int diameterOfBinaryTree(TreeNode *root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0, ld = 0, rd = 0;
    ld = diameterOfBinaryTree(root->left, &lh);
    rd = diameterOfBinaryTree(root->right, &rh);

    *height = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ld, rd));
}