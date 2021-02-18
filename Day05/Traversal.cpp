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

void Preorder(TreeNode * root) {
    if (root != NULL) {
        // N L R
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(TreeNode * root) {
    if (root != NULL) {
        // L N R
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Postorder(TreeNode * root) {
    if (root != NULL) {
        // L R N
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int Height(TreeNode * root) {
    if (root == NULL) return 0;
    else {
        return 1 + max(Height(root->left), Height(root->right));
    }
}

void printGivenLevel(TreeNode * root, int level) {
    if (root == NULL) 
        return;
    if (level == 1) {
        cout << root->data << " ";
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }  
}

void LevelOrder(TreeNode * root) {
    if (root == NULL)
        return;
    int levels = Height(root);
    for (int level = 1; level <= levels; level++) {
        printGivenLevel(root, level);
    }
}

void LevelOrderLineByLine(TreeNode * root) {
    if (root == NULL)
        return;
    int levels = Height(root);
    for (int level = 1; level <= levels; level++) {
        printGivenLevel(root, level);
        cout << "\n";
    }
}

void ReverseLevelOrderLineByLine(TreeNode * root) {
    if (root == NULL)
        return;
    int levels = Height(root);
    for (int level = levels; level >= 1; level--) {
        printGivenLevel(root, level);
        cout << "\n";
    }
}


void LevelOrderIterative(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode * temp;
    while (!Q.empty()) {
        temp = Q.front(); Q.pop();
        cout << temp->data << " ";
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
}

void LevelOrderIterativeLineByLine(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode*> Q;
    Q.push(root);
    Q.push(NULL);
    TreeNode * temp;
    while (!Q.empty()) {
        temp = Q.front(); Q.pop();
        if (temp == NULL) {
            if (Q.empty()) 
                return;
            else {
                Q.push(NULL);
                cout << "\n";
            }
        } else {
            cout << temp->data << " ";
            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }
    }
}

void ReverseLevelOrderIterative(TreeNode * root) {
    if (root == NULL)
        return;
    queue<TreeNode*> Q;
    Q.push(root);
    Q.push(NULL);
    stack<TreeNode*> S;
    TreeNode * temp;
    while (!Q.empty()) {
        temp = Q.front(); Q.pop();
        if (temp == NULL) {
            if (Q.empty()) 
                return;
            else {
                Q.push(NULL);
                S.push(NULL);
            }
        } else {
            S.push(temp);
            if (temp->right)
                Q.push(temp->right);
            if (temp->left)
                Q.push(temp->left);
        }
    }

    while (!S.empty()) {
        temp = S.top(); S.pop();
        if (temp == NULL)
            cout << "\n";
        else 
            cout << temp->data << "\n";
        
    }
}

void PreorderIterative(TreeNode * root) {
    if (root == NULL) return;
    stack<TreeNode*> S;
    while (1) {
        while (root != NULL) {
            cout << root->data << " ";
            S.push(root);
            root = root->left;
        }
        if (S.empty())
            return;
        root = S.top(); S.pop();
        root = root->right;
    }
}

void InorderIterative(TreeNode * root) {
    if (root == NULL) return;
    stack<TreeNode*> S;
    while (1) {
        while (root != NULL) {
            S.push(root);
            root = root->left;
        }
        if (S.empty())
            return;
        root = S.top(); S.pop();
        cout << root->data << " ";
        root = root->right;
    }
}

void PostorderIterative(TreeNode * root) {
    if (root == NULL) {
        return;
    }

    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        root = s1.top(); s1.pop();
        s2.push(root);

        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }

    while (!s2.empty()) {
        int data = s2.top()->data; s2.pop();
        cout << data << " ";
    }
}

int main() {
    return 0;
}