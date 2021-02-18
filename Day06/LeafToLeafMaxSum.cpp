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

int leafToleafMaxSum(TreeNode *root, int* sum) {
    if (root == NULL) {
        *sum = 0;
        return 0;
    }
    if (isLeaf(root)) {
        *sum = 0;
        return root->data;
    }

    int leftSum = 0, rightSum = 0;
    leftSum = leafToleafMaxSum(root->left, sum);
    rightSum = leafToleafMaxSum(root->right, sum);
    if (root->left != NULL && root->right != NULL) {
        // Case when both left and right chilren exist
        *sum = max(*sum, leftSum + rightSum + root->data); 
        return max(leftSum, rightSum) + root->data;
    } else if (root->left != NULL) {
        return root->data + rightSum;
    } else {
        // case when root->left == NULL  
        // root->right may or may not be NULL.
        return root->data + leftSum;

    }
}