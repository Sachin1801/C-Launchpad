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

void even_odd(node *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        cout << head << endl;
    }
    node *ohead = NULL, *ehead = NULL, *otemp = NULL, *etemp = NULL;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data & 1)
        {
            if (ohead == NULL)
            {
                ohead = temp;
            }
        }
        else if (temp->data % 2 == 0)
        {
            if (ehead == NULL)
            {
                ehead = temp;
            }
        }

        if (ohead != NULL && ehead != NULL)
        {
            break;
        }

        temp = temp->next;
    }

    if (ehead == NULL || ohead == NULL)
    {
        cout << head << endl;
        return;
    }

    otemp = ohead;
    etemp = ehead;

    temp = head;

    while (temp != NULL)
    {

        if (temp != etemp && !(temp->data & 1))
        {
            etemp->next = temp;
            etemp = temp;
        }
        else if (temp != otemp && (temp->data & 1))
        {
            otemp->next = temp;
            otemp = temp;
        }
        temp = temp->next;
    }

    otemp->next = ehead;
    etemp->next = NULL;

    cout << ohead << endl;
}

int main()
{
    int n;
    cin >> n;
    node *head = take_input(n);
    even_odd(head);
    return 0;
}