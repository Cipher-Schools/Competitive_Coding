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

void printAllPaths(TreeNode * root, vector<int>& path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->data);
    if (isLeaf(root)) {
        for (int i = 0; i <path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    } else {
        printAllPaths(root->left, path);
        printAllPaths(root->right, path);
    }
    // backtracking step
    path.pop_back();
}