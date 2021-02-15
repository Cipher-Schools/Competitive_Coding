#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
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

    Node *reverseLinkedListHelper(Node *head)
    {
        if (head == NULL)
            return NULL;

        Node *curr = head, *next = NULL, *prev = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return head;
    }
};

Node *addTwo(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    Node dummy;
    Node *result = &dummy, *ptr = a, *qtr = b;
    int carry = 0, sum = 0;
    while (ptr != NULL || qtr != NULL)
    {
        sum = carry + (ptr != NULL ? ptr->data : 0) + (qtr != NULL ? qtr->data : 0);
        carry = sum / 10;
        sum %= 10;
        result->next = new Node(sum);
        result = result->next;

        if (ptr != NULL)
        {
            ptr = ptr->next;
        }

        if (qtr != NULL)
        {
            qtr = qtr->next;
        }
    }

    if (carry > 0)
    {
        result->next = new Node(carry);
    }

    return dummy.next;
}

int main()
{
    SinglyLinkedList a, b;
    for (int i = 1; i <= 9; i++)
    {
        a.insertAtBeginning(i);
        b.insertAtBeginning(10 - i);
    }
    a.printList();
    b.printList();
    SinglyLinkedList c;
    c.head = addTwo(a.head, b.head);
    c.printList();
}