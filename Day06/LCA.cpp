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

TreeNode * LCA(TreeNode * root, TreeNode *a, TreeNode * b) {
    if (root == NULL) 
        return NULL;
    if (root == a || root == b) {
        return root;
    }
    TreeNode *l = LCA(root->left, a, b);
    TreeNode *r = LCA(root->right, a, b);
    if (l != NULL && r != NULL) {
        // This is our least commmon ancestor
        return root;
    } else {
        return (l != NULL? l : r);
    }
}

bool isLeaf(TreeNode * root) {
    return (root->left == NULL && root->right == NULL);
}

int leafToleafMaxSum(TreeNode *root, int* sum) {
    if (root == NULL) {
        *sum = 0;
        return 0;
    }
    if (isLeaf(root)) {
        *sum = 0;
        return root->data;
    }

    int lh = 0, rh = 0, ld = 0, rd = 0;
    ld = leafToleafMaxSum(root->left, &lh);
    rd = leafToleafMaxSum(root->right, &rh);
    if (root->left != NULL && root->right != NULL) {
        *sum = max(*sum, lh + rh + root->data); 
        return max(lh, rh) + root->data;
    }

    return max(ld, rd);
}