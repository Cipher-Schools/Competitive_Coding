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

void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "\n";
}

int getSize(Node *head)
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

Node *cutInHalf(Node *head)
{
    Node *slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow->next;
    slow->next = NULL;
    return middle;
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head, *next = NULL, *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *alternativeMerge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    else
    {
        Node *p, *q;
        while (a != NULL && b != NULL)
        {
            p = a->next;
            q = b->next;
            a->next = b;
            a = p;
            b->next = a;
            b = q;
        }
    }
}

Node *reorderLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // cut in half
    Node *second = cutInHalf(head);
    second = reverse(second);
    // alternate merge (*)
    return alternativeMerge(head, second);
}

int main()
{
}