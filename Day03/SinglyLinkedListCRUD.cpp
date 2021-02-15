#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // default constructor
    Node()
    {
        // constructor chaining
        Node(0);
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        this->head = NULL;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }

    void insertAtPosition(int data, int position)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *p = head, *q;
            int k = 1;
            while (p != NULL && k < position)
            {
                k++;
                q = p;
                p = p->next;
            }
            q->next = newNode;
            newNode->next = p;
        }
    }

    void printList()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "\n";
    }

    int getSize()
    {
        Node *ptr = head;
        int size = 0;
        while (ptr != NULL)
        {
            size++;
            ptr = ptr->next;
        }
        return size;
    }

    void deleteFromBeginning()
    {
        if (head == NULL)
            return;
        Node *ptr = head;
        head = head->next;
        delete ptr;
    }

    void deleteFromEnd()
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            Node *ptr = head;
            head = head->next;
            delete ptr;
            return;
        }
        else
        {
            Node *ptr = head, *qtr;
            while (ptr->next != NULL)
            {
                qtr = ptr;
                ptr = ptr->next;
            }
            qtr->next = NULL;
            delete ptr;
        }
    }

    void deleteKey(int key)
    {
        Node *curr = head, *prev;
        if (curr != NULL && curr->data == key)
        {
            head = curr->next;
            delete curr;
            return;
        }
        else
        {
            while (curr != NULL && curr->data != key)
            {
                prev = curr;
                curr = curr->next;
            }

            if (curr == NULL)
            {
                return;
            }

            prev->next = curr->next;
            delete curr;
        }
    }

    void deleteFromPosition(int position)
    {
        if (head == NULL)
        {
            return;
        }
        Node *ptr = head, *qtr = NULL;
        if (position == 1)
        {
            head = head->next;
            delete ptr;
        }
        else
        {
            int count = 1;
            while (count < position & ptr != NULL)
            {
                qtr = ptr;
                ptr = ptr->next;
                count++;
            }
            if (ptr != NULL)
            {
                qtr->next = ptr->next;
                delete ptr;
            }
        }
    }
};

int main()
{
    SinglyLinkedList sll;
    for (int i = 5; i >= 1; i--)
        sll.insertAtBeginning(i);
    sll.printList();

    for (int i = 6; i <= 10; i++)
        sll.insertAtEnd(i);
    sll.printList();

    sll.insertAtPosition(100, 1);
    cout << sll.getSize() << endl;
    sll.printList();

    sll.insertAtPosition(100, 15);
    cout << sll.getSize() << endl;
    sll.printList();

    sll.insertAtPosition(100, 2);
    cout << sll.getSize() << endl;
    sll.printList();

    sll.deleteFromBeginning();
    sll.printList();
    sll.deleteFromEnd();
    sll.printList();
    sll.deleteKey(7);
    sll.printList();
    sll.deleteFromPosition(3);
    sll.printList();
}