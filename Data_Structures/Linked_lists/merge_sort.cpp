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

node *midpoint(node *head)
{
    // the case when the linked list have only 1 or 2 nodes in it
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast->next != NULL and fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *mergeSort(node *head)
{
    //base case
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    //recursive case
    //1. Break the linked list in two parts about the midpoint of the linked list
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    //2.Sort the two small unsorterd linked list ]
    a = mergeSort(a);
    b = mergeSort(b);

    //3. You need to combine the linked list / merge them using merge function
    node *c = merge(a, b);
    return c;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    head = mergeSort(head);
    cout << head;
    return 0;
}