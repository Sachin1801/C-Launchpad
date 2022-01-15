#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    //Constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertatHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    //else if head is not null but already pointing to some other data box
    node *n = new node(d);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

node *take_input()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        insertatHead(head, d);
        cin >> d;
    }
    return head;
}

ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head) // now we pass the head here by reference because we need to send the value in the main too
{
    head = take_input();
    return is;
}

node *after_k_jumps(node *head, int k)
{
    int jump = 0;
    node *fast = head;
    while (jump != k)
    {
        fast = fast->next;
        jump++;
    }
    return fast;
}

node *kthnode(node *head, int k)
{
    //ending condition
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *fast = after_k_jumps(head, k);
    node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node *head = NULL;
    cin >> head;
    int k;
    cin >> k;
    node *ans = kthnode(head, k);
    cout << ans->data;
    return 0;
}