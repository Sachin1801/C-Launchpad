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

void opencycle(node *fast, node *slow, node *head)
{
    slow = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
    // print(head);
}

bool detectCycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            opencycle(fast, slow, head);
            return true;
        }
    }
    return false;
}

int main()
{
    node *head = NULL;
    cin >> head;
    detectCycle(head);
    return 0;
}