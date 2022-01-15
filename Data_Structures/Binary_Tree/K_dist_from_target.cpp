#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildtree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    //otherwise create new parent/ root node and take input recursively first from the left and then from the right
    node *root = new node(d);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

void printKthLevel(node *root, int k)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

int printAtDistance(node *root, node *target, int k)
{
    //base case
    if (root == NULL)
    {
        return -1;
    }
    //reach the target node fromt the top of the tree
    if (root == target)
    {
        printKthLevel(target, k);
        return 0;
    }
    //next step return back to the ancestor
    int DL = printAtDistance(root->left, target, k);
    if (DL != -1)
    {
        //Again 2 cases
        //Ancestor itself or the right of the ancestor
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->right, k - 2 - DL);
        }
        return 1 + DL;
    }
    int DR = printAtDistance(root->right, target, k);
    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->left, k - 2 - DR);
        }
        return 1 + DR;
    }
    //Node was not present in left or right subtree of given node
    return -1;
}

void levelorderbuild(node *&root)
{
    int d;
    cin >> d;
    root = new node(d);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *n = q.front();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            n->left = new node(c1);
            q.push(n->left);
        }
        if (c2 != -1)
        {
            n->left = new node(c2);
            q.push(n->right);
        }
    }
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
}

int main()
{
    node *root = buildtree();
    node *target = root->left->left;
    bfs(root);
    cout << endl;
    printAtDistance(root, target, 2);
    return 0;
}