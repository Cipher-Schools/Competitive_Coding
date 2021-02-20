#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
  public:
    T data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class CircularLinkedList
{
  private:
    Node<T> *head;

  public:
    int size;

    CircularLinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    Node<T> *createNode(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = newNode;
        return newNode;
    }

    void PushFront(T data)
    {
        Node<T> *newNode = this->createNode(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else if (this->head->next == this->head)
        {
            this->head->next = newNode;
            newNode->next = this->head;
        }
        else
        {
            newNode->next = this->head->next;
            this->head->next = newNode;
        }
        this->head = newNode;
        this->size++;
    }

    void PushBack(T data)
    {
        Node<T> *newNode = this->createNode(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else if (this->head->next == this->head)
        {
            this->head->next = newNode;
            newNode->next = this->head;
        }
        else
        {
            Node<T> *p = this->head;
            while (p->next != this->head)
            {
                p = p->next;
            }
            p->next = newNode;
            newNode->next = head;
        }
        this->size++;
    }

    void Insert(T data, int position)
    {
        Node<T> *newNode = this->createNode(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else if (position == 1)
        {
            newNode->next = this->head->next;
            this->head->next = newNode;
            this->head = newNode;
        }
        else
        {
            Node<T> *p = this->head;
            int k = 1;
            while (k < position - 1 && p->next != this->head)
            {
                k++;
                p = p->next;
            }
            newNode->next = p->next;
            p->next = newNode;
        }

        this->size++;
    }

    void PopFront()
    {
        if (this->head == NULL)
        {
            throw "Circular linked list empty";
            return;
        }
        else if (this->head->next == this->head)
        {
            delete (this->head);
            this->head = NULL;
        }
        else
        {
            Node<T> *p = this->head;
            while (p->next != this->head)
            {
                p = p->next;
            }
            p->next = this->head->next;
            p = this->head;
            this->head = this->head->next;
            delete (p);
        }

        this->size--;
    }

    void PopBack()
    {
        if (this->head == NULL)
        {
            throw "Circular linked list empty";
            return;
        }
        else if (this->head->next == this->head)
        {
            delete (this->head);
            this->head = NULL;
        }
        else
        {
            Node<T> *p = this->head;
            Node<T> *q = this->head;
            do
            {
                q = p;
                p = p->next;
            } while (p->next != this->head);
            q->next = p->next;
            delete (p);
        }
        this->size--;
    }

    void PrintList()
    {
        if (this->head == NULL)
        {
            return;
        }
        else if (this->head->next == this->head)
        {
            cout << this->head->data << "\n";
        }
        else
        {
            Node<T> *p = this->head;
            do
            {
                cout << p->data << " ";
                p = p->next;
            } while (p != this->head);
            cout << "\n";
        }
    }
};