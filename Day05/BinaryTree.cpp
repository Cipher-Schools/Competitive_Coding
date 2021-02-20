#include <bits/stdc++.h>
using namespace std;

template <class T>
class BTNode
{
  public:
    T data;
    BTNode<T> *left, *right;

    BTNode()
    {
        this->left = this->right = NULL;
    }

    BTNode(T data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

template <class T>
class BinaryTree
{
  private:
    BTNode<T> *root;
    int Size;

  public:
    BinaryTree()
    {
        this->root = NULL;
        this->Size = 0;
    }

    void Insert(T data)
    {
        BTNode<T> *newNode = new BTNode<T>(data);
        if (!this->root)
        {
            this->root = newNode;
        }
        else
        {
            BTNode<T> *p = this->root;
            queue<BTNode<T> *> Q;
            Q.push(p);
            while (!Q.empty())
            {
                p = Q.front();
                Q.pop();

                if (!p->left)
                {
                    p->left = newNode;
                    return;
                }
                else
                {
                    Q.push(p->left);
                }

                if (!p->right)
                {
                    p->right = newNode;
                    return;
                }
                else
                {
                    Q.push(p->right);
                }
            }
        }

        this->Size++;
    }

    void InorderTraversalHelper(BTNode<T> *temp)
    {
        if (temp)
        {
            InorderTraversalHelper(temp->left);
            cout << temp->data << " ";
            InorderTraversalHelper(temp->right);
        }
    }

    void InorderTraversal()
    {
        BTNode<T> *temp = this->root;
        InorderTraversalHelper(temp);
    }

    void PreorderTraversalHelper(BTNode<T> *temp)
    {
        if (temp)
        {
            cout << temp->data << " ";
            PreorderTraversalHelper(temp->left);
            PreorderTraversalHelper(temp->right);
        }
    }

    void PreorderTraversal()
    {
        BTNode<T> *temp = this->root;
        PreorderTraversalHelper(temp);
    }

    void PostorderTraversalHelper(BTNode<T> *temp)
    {
        if (temp)
        {
            PostorderTraversalHelper(temp->left);
            PostorderTraversalHelper(temp->right);
            cout << temp->data << " ";
        }
    }

    void PostorderTraversal()
    {
        BTNode<T> *temp = this->root;
        PostorderTraversalHelper(temp);
    }
};