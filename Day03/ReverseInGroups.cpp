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

    Node *reverseLinkedListInGroups(Node *head, int K)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *curr = head, *next = NULL, *prev = NULL;
        int k = 0;
        while (curr != NULL && k < K)
        {
            k++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (next != NULL)
            head->next = reverseLinkedListInGroups(next, K);
        return prev;
    }

    void reverseLinkedListInGroups(int K)
    {
        this->head = reverseLinkedListInGroups(head, K);
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.printList();
    for (int i = 1; i <= 11; i++)
    {
        sll.insertAtBeginning(i);
        sll.printList();
        sll.reverseLinkedListInGroups(3);
        sll.printList();
    }
}