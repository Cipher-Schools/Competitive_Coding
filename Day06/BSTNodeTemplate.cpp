#include <bits/stdc++.h>
using namespace std;

template <class T>
class BSTNode
{
  public:
    T data;
    BSTNode<T> *left, *right;

    BSTNode()
    {
        this->left = this->right = NULL;
    }

    BSTNode(T data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

template <class T>
class BinarySearchTree
{
  private:
    BSTNode<T> *root;
    int Size;

    BSTNode<T> *InsertHelper(BSTNode<T> *curr, T data)
    {
        if (!curr)
        {
            return new BSTNode<T>(data);
        }

        if (curr->data > data)
        {
            curr->left = this->InsertHelper(curr->left, data);
        }
        else
        {
            curr->right = this->InsertHelper(curr->right, data);
        }
        return curr;
    }

    BSTNode<T> *RemoveHelper(BSTNode<T> *curr, T data)
    {
        if (curr == NULL)
        {
            return NULL;
        }

        if (curr->data > data)
        {
            curr->left = RemoveHelper(curr->left, data);
            return curr;
        }
        else if (curr->data < data)
        {
            curr->right = RemoveHelper(curr->right, data);
            return curr;
        }
        else
        {
            if (!curr->left && !curr->right)
            {
                delete (curr);
                return NULL;
            }
            else if (!curr->left)
            {
                BSTNode<T> *temp = curr->right;
                delete (curr);
                return temp;
            }
            else if (!curr->right)
            {
                BSTNode<T> *temp = curr->left;
                delete (curr);
                return temp;
            }
            else
            {
                curr->data = GetMax(curr->left);
                curr->left = RemoveHelper(curr->left, curr->data);
                return curr;
            }
        }
    }

    void InorderTraversalHelper(BSTNode<T> *temp)
    {
        if (temp)
        {
            InorderTraversalHelper(temp->left);
            cout << temp->data << " ";
            InorderTraversalHelper(temp->right);
        }
    }

    void PreorderTraversalHelper(BSTNode<T> *temp)
    {
        if (temp)
        {
            cout << temp->data << " ";
            PreorderTraversalHelper(temp->left);
            PreorderTraversalHelper(temp->right);
        }
    }

    void PostorderTraversalHelper(BSTNode<T> *temp)
    {
        if (temp)
        {
            PostorderTraversalHelper(temp->left);
            PostorderTraversalHelper(temp->right);
            cout << temp->data << " ";
        }
    }

  public:
    BinarySearchTree()
    {
        this->root = NULL;
        this->Size = 0;
    }

    void Insert(T data)
    {
        BSTNode<T> *curr = this->root;
        this->root = this->InsertHelper(curr, data);
        this->Size++;
    }

    T GetMin(BSTNode<T> *curr)
    {
        if (curr == NULL)
        {
            throw "Can't find min value. BST empty!!";
        }
        else
        {
            while (curr->left)
            {
                curr = curr->left;
            }
            return curr->data;
        }
    }

    T GetMax(BSTNode<T> *curr)
    {
        if (curr == NULL)
        {
            throw "Can't find max value. BST empty!!";
        }
        else
        {
            while (curr->right)
            {
                curr = curr->right;
            }
            return curr->data;
        }
    }

    void Remove(T data)
    {
        BSTNode<T> *curr = this->root;
        this->root = RemoveHelper(curr, data);
        this->Size--;
    }

    void InorderTraversal()
    {
        BSTNode<T> *temp = this->root;
        InorderTraversalHelper(temp);
        cout << "\n";
    }

    void PreorderTraversal()
    {
        BSTNode<T> *temp = this->root;
        PreorderTraversalHelper(temp);
        cout << "\n";
    }

    void PostorderTraversal()
    {
        BSTNode<T> *temp = this->root;
        PostorderTraversalHelper(temp);
        cout << "\n";
    }

    void LevelOrderTraversal()
    {
        BSTNode<T> *p = this->root;
        queue<BSTNode<T> *> Q;
        Q.push(p);
        while (!Q.empty())
        {
            p = Q.front();
            cout << p->data << " ";
            Q.pop();

            if (p->left)
            {
                Q.push(p->left);
            }

            if (p->right)
            {
                Q.push(p->right);
            }
        }
        cout << "\n";
    }
};