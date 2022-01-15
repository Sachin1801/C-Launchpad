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

bool checkpalindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            if (head->data == temp->data)
            {
                temp == NULL;
                checkpalindrome(head->next);
            }
            return false;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    node *head = take_input(n);
    if (checkpalindrome(head))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}