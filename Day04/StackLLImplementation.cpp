#include <bits/stdc++.h>
using namespace std;

template <class T>
class LLStackNode
{
  public:
    T data;
    LLStackNode *next;
    LLStackNode()
    {
        this->next = NULL;
    }

    LLStackNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// LinkedList Implementation
template <class T>
class LLStack
{
  private:
    LLStackNode<T> *head;
    int size;

  public:
    LLStack()
    {
        this->head = NULL;
        this->size = 0;
    }

    bool Empty()
    {
        return (this->head == NULL);
    }

    void Push(T data)
    {
        LLStackNode<T> *newNode = new LLStackNode<T>(data);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

    void Pop()
    {
        if (this->Empty())
        {
            throw "ArrayStack underflow";
        }
        else
        {
            LLStackNode<T> *p = this->head;
            this->head = this->head->next;
            delete (p);
            this->size--;
        }
    }

    T Top()
    {
        if (this->Empty())
        {
            throw "ArrayStack underflow";
        }
        else
        {
            return this->head->data;
        }
    }

    int Size()
    {
        return (this->size);
    }
};