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

void insert(node *&head, int d)
{
    node *n = new node(d);
    node *temp = head;
    if (temp != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
    else
    {
        n->next = n;
        head = n;
    }
}

void print(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    return;
}

node *getNode(node *&head, int data)
{
    node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    //Out of the loop , we have to check for the last node too
    if (temp->data == data)
    {
        return temp;
    }
    return NULL;
}

void deleteNode(node *head, int data)
{
    node *del = getNode(head, data);
    if (del == NULL)
    {
        return;
    }
    //otherwise
    //if the head is the node to be deleted
    if (head == del)
    {
        head = head->next;
    }
    //otherwise the normal steps , we iterate over the linked list until we find the del node
    node *temp = head;
    while (temp->next == del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    print(head);
    cout << endl;
    deleteNode(head, 4);
    print(head);
    cout << endl;
    deleteNode(head, 2);
    print(head);
    cout << endl;
    return 0;
}