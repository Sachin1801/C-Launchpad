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

//function (Procedural programming )
void build()
{
}
//Passing the pointer by reference
void insertatHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    //else if head is not null but already pointing to some other data box
    node *n = new node(d);
    n->next = head;
    head = n;
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

//To calculate the length of the linked list
int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
}

void insertatTail(node *&head, int d)
{
    //if the linked list is already empty
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    //assumiong we are not maintaining the count of the tail , and now we are finding it
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
}

void insertinmiddle(node *&head, int d, int p)
{
    //To check for the corner case
    if (head == NULL || p == 0)
    {
        insertatHead(head, d);
        return;
    }
    else if (p > length(head))
    {
        insertatTail(head, d);
    }
    //Case to insert the element in the middle
    else
    {
        //Take p-1 jumps
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        //create a new node
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
    return;
}

void deletehead(node *&head)
{
    //if the list is already empty
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

void deleteinmiddle(node *&head, int p)
{
    //corner case
    if (head == NULL || p == 0)
    {
        return;
    }
    if (p > length(head))
    {
        return;
    }
    node *prev = NULL;
    int jump = 1;
    node *temp = head;
    while (jump <= p - 1)
    {
        prev = temp;
        temp = temp->next;
        jump++;
    }
    prev->next = temp->next;
    delete temp;
}

void deleteTail(node *&head)
{
    //if the linked list is empty
    if (head == NULL)
    {
        return;
    }
    node *prev = NULL;
    node *tail = head;
    while (tail->next != NULL)
    {
        prev = tail;
        tail = tail->next;
    }
    delete tail;
    prev->next = NULL;
}

//Search operation in linked list
//linear search
bool search(node *head, int key)
{
    node *temp = head;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

//Recursive approach to search an element in the linked list
bool search_recursively(node *head, int key)
{
    //base case
    if (head == NULL)
    {
        return false;
    }
    //recursive case
    if (head->data == key)
    {
        return true;
    }
    else
    {
        return search_recursively(head->next, key);
    }
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

int main()
{
    // node *head = take_input();
    // node *head2 = take_input();
    node *head;
    node *head2;
    cin >> head >> head2;

    cout << head << head2;
    // print(head);

    // node *head = NULL;
    // insertatHead(head, 3);
    // insertatHead(head, 2);
    // insertatHead(head, 1);
    // insertatHead(head, 0);
    // insertatHead(head, 3);

    // insertinmiddle(head, 10, 3);
    // insertatTail(head, 22);
    // deleteTail(head);
    // deleteinmiddle(head, 2);

    // print(head);
    // int key;
    // cin >> key;
    // if (search_recursively(head, key))
    // {
    //     cout << "Element present in list " << endl;
    // }
    // else
    // {
    //     cout << "Element not found in list " << endl;
    // }
    return 0;
}