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

TreeNode* insert(TreeNode * root, int x) {
    if (root == NULL) {
        return new TreeNode(x);
    } 
    if (root->data > x) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

TreeNode * deletion(TreeNode * root, int x) {
    if (root == NULL) return NULL;

    if (root->data < x) {
        root->right = deletion(root->right, x);
    }  else if (root->data > x) {
        root->left = deletion(root->left, x);
    } else {
        // this is the node which I want to delete 
        // Check how many children it has  
        TreeNode * delNode; 
        if (root->left == NULL) {
            delNode = root->right;
            delete root;
            return delNode;
        } else if (root->right == NULL) {
            delNode = root->left;
            delete root;
            return delNode; 
        }

        // For childen
        TreeNode *minVal = getMinNode(root->right); 
        root->data = minVal->data;
        root->right = deletion(root->right, minVal->data);

        // TreeNode *maxVal = getMaxNode(root->left); 
        // root->data = maxVal->data;
        // root->left = deletion(root->left, maxVal->data);

    }
}