
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

void printList(Node * head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "\n";
}

int getSize(Node * head)
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

Node * findIntersection(Node * a, Node * b) {
    if (a == NULL || b == NULL)
        return NULL;

    Node dummy;
    Node *result = &dummy;
    Node *ptr = a, *qtr = b;
    while(ptr != NULL && qtr != NULL) {
        if (ptr->data == qtr->data) {
            result->next = new Node(ptr->data);
            result = result->next;
            ptr = ptr->next;
            qtr = qtr->next;
        } else if (ptr->data < qtr->data) {
            ptr = ptr->next;
        } else {
            qtr = qtr->next;
        }
    }
    return dummy.next;
}

int main()
{
}