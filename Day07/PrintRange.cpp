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

void range(TreeNode * root, int start, int end, vector<int>& result) {
    if (root == NULL) return;

    if (root->data < start)
        range(root->right, start, end, result);
    else if (root->data >= start && root->data <= end) {
        range(root->right, start, end, result);
        result.push_back(root->data);
        range(root->left, start, end, result);
    } else 
        range(root->left, start, end, result);
}

vector<int> range(TreeNode * root, int start, int end) {
    vector<int> result;
    range(root, start, end, result);
    return result;
}