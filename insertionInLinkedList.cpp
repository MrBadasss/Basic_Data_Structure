#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void printLinkedList(node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void insertAtTail(node *&head, int v)
{
    node *newNode = new node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void insertAtAnyIdx(node *&head, int idx, int v)
{
    node *newNode = new node(v);
    if (idx == 0 and head == NULL)
    {
        head = newNode;
        printLinkedList(head);
        return;
    }
    else if (idx == 0)
    {
        newNode->next = head;
        head = newNode;
        printLinkedList(head);
        return;
    }

    node *tmp = head;
    for (int i = 1; i <= idx - 1; i++)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            cout << "Invalid" << endl;
            return;
        }
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    printLinkedList(head);
}

int main()
{
    node *head = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insertAtTail(head, val);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int idx;
        cin >> idx >> val;
        insertAtAnyIdx(head, idx, val);
    }

    return 0;
}
