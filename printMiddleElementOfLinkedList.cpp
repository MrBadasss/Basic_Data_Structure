#include <bits/stdc++.h>
using namespace std;
int elementCount = 0;
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
    elementCount++;
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
    // tmp is now the last node
    tmp->next = newNode;
}
void printMid(node *head)
{
    int mid1, mid2;
    mid1 = (elementCount + 1) / 2;
    int idx = 1;
    node *tmp = head;
    while (tmp != NULL)
    {

        if (idx == mid1 and elementCount % 2 == 1)
        {
            cout << tmp->val << endl;
            break;
        }
        else if (idx == mid1)
        {
            cout << tmp->val << " " << tmp->next->val << endl;
            break;
        }
        idx++;
        tmp = tmp->next;
    }
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
    printMid(head);

    return 0;
}