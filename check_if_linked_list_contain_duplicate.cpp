#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        next = NULL;
        this->val = val;
    }
};
void insertAtTail(node *&head, int val)
{
    node *newNode = new node(val);
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
bool checkDuplicate(node *head)
{
    vector<int> v(101, 0);
    node *tmp = head;
    while (true)
    {
        v[tmp->val]++;

        if (tmp->next == NULL)
        {
            break;
        }
        tmp = tmp->next;
    }

    sort(v.begin(), v.end());
    // for (auto x : v)
    //     cout << x << " ";
    // cout << endl;
    return v.back() > 1;
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
    bool isDuplicate = checkDuplicate(head);
    isDuplicate ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}