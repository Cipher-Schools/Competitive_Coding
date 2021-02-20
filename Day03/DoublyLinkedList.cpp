#include <bits/stdc++.h>
using namespace std;

template <class T>
class DLLNode
{
  public:
    T data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode()
    {
        this->prev = this->next = NULL;
    }

    DLLNode(T data)
    {
        this->data = data;
        this->prev = this->next = NULL;
    }
};

template <class T>
class DoublyLinkedList
{
  private:
    DLLNode<T> *head;

  public:
    int size;
    DoublyLinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    void PushFront(T data)
    {
        DLLNode<T> *newNode = new DLLNode<T>(data);
        if (this->head != NULL)
        {
            newNode->next = this->head;
            this->head->prev = newNode;
        }
        this->head = newNode;
        this->size++;
    }

    void PushBack(T data)
    {
        DLLNode<T> *newNode = new DLLNode<T>(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            DLLNode<T> *p = this->head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newNode;
            newNode->prev = p;
        }
        this->size++;
    }

    void Insert(T data, int position)
    {
        DLLNode<T> *newNode = new DLLNode<T>(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else if (position == 1)
        {
            newNode->next = this->head;
            this->head->prev = newNode;
        }
        else
        {
            DLLNode<T> *p = this->head;
            int k = 1;
            while (p && k < position - 1)
            {
                k++;
                p = p->next;
            }

            newNode->next = p->next;
            p->next->prev = newNode;
            newNode->prev = p;
            p->next = newNode;
        }

        this->size++;
    }

    void PopFront()
    {
        if (this->head == NULL)
        {
            throw "Doubly linked list empty!!";
            return;
        }
        else
        {
            DLLNode<T> *p = this->head;
            this->head = this->head->next;
            delete (p);
        }

        this->size--;
    }

    void PopBack()
    {
        if (this->head == NULL)
        {
            throw "Doubly linked list empty!!";
            return;
        }
        else if (this->head->next == NULL)
        {
            delete (this->head);
            this->head = NULL;
        }
        else
        {
            DLLNode<T> *p = this->head;
            while (p->next != NULL)
            {
                p = p->next;
            }

            p->prev->next = NULL;
            delete (p);
        }
        this->size--;
    }

    T GetElement(int position)
    {
        if (this->head == NULL)
        {
            throw "Doubly linked list empty!!";
            // return;
        }
        else if (this->size < position)
        {
            throw "Given position doesnot exist!!";
            // return;
        }
        else
        {
            int k = 1;
            DLLNode<T> *p = this->head;
            while (p && k < position)
            {
                p = p->next;
                k++;
            }

            return p->data;
        }
    }

    void Remove(int position)
    {
        if (this->head == NULL)
        {
            throw "Doubly linked list empty!!";
            // return;
        }
        else if (this->size < position)
        {
            throw "Given position doesnot exist!!";
            // return;
        }
        else
        {
            DLLNode<T> *p = this->head;
            if (position == 1)
            {
                this->head = this->head->next;
                delete (p);
            }
            else
            {
                int k = 1;
                while (p && k < position)
                {
                    p = p->next;
                    k++;
                }

                DLLNode<T> *q = p->prev;
                p->prev = q;
                q->next = p->next;
                delete (p);
            }
        }

        this->size--;
    }

    void DeleteList()
    {
        if (this->head == NULL)
        {
            return;
        }
        else
        {
            DLLNode<T> *p = this->head;
            DLLNode<T> *q = NULL;
            while (p)
            {
                q = p->next;
                delete (p);
                p = q;
            }
        }
        this->head = NULL;
        this->size = 0;
    }

    int Size()
    {
        return this->size;
    }
};