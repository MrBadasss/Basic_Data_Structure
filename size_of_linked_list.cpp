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
int countSizeOfLinkedList(node *head)
{
    int sz = 0;
    while (head->next != NULL)
    {
        head = head->next;
        sz++;
    }
    return sz + 1;
}
int main()
{
    node *head = NULL;
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insertAtTail(head, val);
    }
    int sz = countSizeOfLinkedList(head);
    cout << sz << endl;

    return 0;
}