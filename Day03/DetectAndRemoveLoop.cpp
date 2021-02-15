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

    bool detectLoop()
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        Node *slow = head, *fast = head;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    void removeLoop()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        Node *slow = head, *fast = head;
        bool loopPresent = false;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                loopPresent = true;
                break;
            }
        }

        if (loopPresent)
        {
            slow = head;
            if (slow == fast)
            {
                while (fast->next != slow)
                {
                    fast = fast->next;
                }
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            // Line removing the loop
            fast->next = NULL;
        }
    }
};

int main()
{
    SinglyLinkedList *sll = new SinglyLinkedList();
    sll->head = new Node(1);
    sll->head->next = new Node(2);
    sll->head->next->next = new Node(3);
    sll->head->next->next->next = new Node(4);
    sll->head->next->next->next->next = new Node(5);
    cout << sll->detectLoop() << "\n";
    sll->head->next->next->next->next->next = sll->head;
    cout << sll->detectLoop() << "\n";
    sll->removeLoop();
    cout << sll->detectLoop() << "\n";
    sll->head->next->next->next->next->next = sll->head->next;
    cout << sll->detectLoop() << "\n";
    sll->removeLoop();
    cout << sll->detectLoop() << "\n";
}