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

Node * removeDuplicateSortedLL(Node * head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node * curr = head;
    Node * nxt = NULL;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            nxt = curr->next;
            curr->next = nxt->next;
            delete nxt;
        } else {
            curr = curr->next;
        }
    }
    return head;

}

class SpecialNode{
    public:
    int data;
    Node *next;
    Node *random;
};

bool isPalindromeHelper(Node ** left, Node * right) {
    // Has the rigght pointer reached the end of LL or not?
    if (right == NULL) {
        return true;
    }
    bool isPalin = isPalindromeHelper(left, right->next);
    if (!isPalin) {
        return false;
    }

    bool dataEqual = ((*left)->data == right->data);
    (*left) = (*left)->next;
    return dataEqual;
}

bool isPalindrome(Node * head){
    return isPalindromeHelper(&head, head);
}

int main()
{
}