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


TreeNode* leastCommonAncestor(TreeNode * root, TreeNode * a, TreeNode * b) {
    if (root == NULL)
        return NULL; 
    if (root->data > a->data && root->data > b->data) 
        return leastCommonAncestor(root->left, a, b);
    else if (root->data < a->data && root->data < b->data) 
        return leastCommonAncestor(root->right, a, b);
    else {
        // [a <= lca <= b] 
        return root;
    } 
}