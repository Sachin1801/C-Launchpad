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

node *take_input(int n)
{
    int d;
    node *head = NULL;
    while (n--)
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

// istream &operator>>(istream &is, node *&head) // now we pass the head here by reference because we need to send the value in the main too
// {
//     head = take_input();
//     return is;
// }

node *createnewnode(node *head, node *curr)
{
    node *temp = curr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = curr;
    return head;
}

void append(int size, node *head, int k)
{
    if (size == 0)
    {
        return;
    }
    if (k >= size || k <= 0)
    {
        cout << head << endl;
        return;
    }
    node *prev = head;
    node *curr = head->next;
    int count = (size - k - 1);
    while (count--)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = NULL;
    head = createnewnode(head, curr);
    cout << head << endl;
    return;
}

int main()
{
    int n;
    cin >> n; //Size of the linked list
    node *head = take_input(n);
    int k;
    cin >> k; // Number of elemnts to append
    append(n, head, k);
    return 0;
}