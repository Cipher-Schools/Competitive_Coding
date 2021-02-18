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

void leftView(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            root = Q.front(); Q.pop();
            if (i == 0) {
                cout << root->data << " ";
            }
            
            if (root->left != NULL) {
                Q.push(root->left);
            }

            if (root->right != NULL) {
                Q.push(root->right);
            }
        }
    }
}

void rightView(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            root = Q.front(); Q.pop();
            if (i == size - 1) {
                cout << root->data << " ";
            }
            
            if (root->left != NULL) {
                Q.push(root->left);
            }

            if (root->right != NULL) {
                Q.push(root->right);
            }
        }
    }
}