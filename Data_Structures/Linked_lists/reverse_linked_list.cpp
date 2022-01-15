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

//Reverse a linked list
void reverse_linked_list(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *N;
    while (curr != NULL)
    {
        //Save the next node
        N = curr->next;
        //Make the current node point to previous
        curr->next = prev;
        //Update P and C , take them one step forward
        prev = curr;
        curr = N;
    }
    head = prev; //as the curr is null so to print it in reverse order we need to make it head so that the print happens in the reversal order
}

//Reverse a linked list
node *RecReverse(node *head) //Less efficient than the iterative reverse (written above)
{
    //base case
    //smallest linked list case too
    if (head->next == NULL or head == NULL)
    {
        return head;
    }
    //recursive case
    node *shead = RecReverse(head->next);

    head->next->next = head;
    head->next = NULL;
    return shead;
}

//Mid point of a linked list
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

int main()
{
    node *head;
    cin >> head;
    // cout << head;

    //Commands to reverse the linked list

    // head = RecReverse(head);
    // cout << head;

    //Command to find the midpoibnt of the linked list
    node *mid = midpoint(head);
    cout << mid->data; // mid->data is written to print the data inside the node
    return 0;
}