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
    // tmp ekhon last node e;
    tmp->next = newNode;
}
bool isLinkedListSorted(node *head)
{
    bool isSorted = true;
    while (head->next != NULL)
    {

        if (head->val > head->next->val)
        {
            isSorted = false;
            break;
        }
        head = head->next;
    }
    return isSorted;
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
    isLinkedListSorted(head) ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}