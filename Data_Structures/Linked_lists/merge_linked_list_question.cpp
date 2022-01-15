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
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *take_input(int s1)
{
    int d;
    node *head = NULL;
    while (s1--)
    {
        cin >> d;
        insertatHead(head, d);
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
    int s1;
    cin >> s1;
    head = take_input(s1);
    return is;
}

//function to merge two linked lists
node *merge(node *a, node *b)
{
    //base case
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    //recursive case
    //Take a new a node pointer
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        node *head1;
        node *head2;
        cin >> head1;
        cin >> head2;
        node *newhead = merge(head1, head2);
        cout << newhead;
    }
    return 0;
}