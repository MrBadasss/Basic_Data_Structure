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

void deleteHead(node *&head)
{
    if (head == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }
    node *tmp = head;
    head = head->next;
    delete tmp;
}
void deleteNodeFromAnyPosition(node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "The list is already empty." << endl;
        return;
    }
    node *deleteNode;
    if (pos == 0)
    {
        deleteNode = head;
        head = deleteNode->next;
        cout << "Deleted Head." << endl;
        delete deleteNode;
        return;
    }
    node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
        {
            cout << "Invalid Postion." << endl;
            return;
        }
    }
    if (tmp->next == NULL)
    {
        cout << "Invalid Positon." << endl;
        return;
    }
    deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    cout << "Deleted Node from Position " << pos << ".\n";
    delete deleteNode;
}
void insertAtHead(node *&head, int v)
{
    cout << "Inserted at Head." << endl;
    node *newNode = new node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void insertAtAnyPosition(node *&head, int pos, int v)
{
    if (head == NULL and pos > 0)
    {
        cout << "Invalid Postion." << endl;
        return;
    }
    node *newNode = new node(v);
    if (pos == 0)
    {
        cout << "Inserted at pos " << pos << endl;
        newNode->next = head;
        head = newNode;
        return;
    }
    node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {

        if (tmp->next == NULL)
        {
            cout << "Invalid Position." << endl;
            return;
        }
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;

    cout << "Inserted at position " << pos << endl;
}
void insertAtTail(node *&head, int v)
{
    node *newNode = new node(v);
    if (head == NULL)
    {
        cout << v << " is inserted at Head." << endl;
        head = newNode;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekhon last node e;
    tmp->next = newNode;

    cout << v << " is inserted at Tail." << endl;
}
void printList(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "The list is: ";
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;

    while (true)
    {
        cout << "Op 0: Terminate." << endl
             << "Op 1: Print list." << endl
             << "Op 2: Insert at Tail." << endl
             << "Op 3: Insert at Head." << endl
             << "Op 4: Insert at any Position." << endl
             << "Op 5: Delete Node from any Position" << endl
             << "Op 6: Delete Head." << endl;
        int op;
        cin >> op;
        if (op == 0)
            break;
        else if (op == 1)
            printList(head);
        else if (op == 2)
        {
            cout << "Enter the node value: ";
            int val;
            cin >> val;
            insertAtTail(head, val);
        }
        else if (op == 3)
        {
            cout << "Enter the node value: ";
            int val;
            cin >> val;
            insertAtHead(head, val);
        }
        else if (op == 4)
        {
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            cout << endl
                 << "Enter the value: ";
            int val;
            cin >> val;
            insertAtAnyPosition(head, pos, val);
        }
        else if (op == 5)
        {
            int pos;
            cout << "Enter the Position: " << endl;
            cin >> pos;
            deleteNodeFromAnyPosition(head, pos);
        }
        else if (op == 6)
            deleteHead(head);

        printList(head);
    }

    return 0;
}