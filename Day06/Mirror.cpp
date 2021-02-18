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

bool isMirror(TreeNode * a, TreeNode * b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    if (a->data == b->data) {
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    } else {
        return false;
    }
}

bool isMiror(TreeNode * root) {
    return isMirror(root->left, root->right);
}