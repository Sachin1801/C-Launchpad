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

void Printrightview(node *root, int level, int &maxlevel)
{
    //base case
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }
    Printrightview(root->right, level + 1, maxlevel);
    Printrightview(root->left, level + 1, maxlevel);
}

int main()
{
    node *root = NULL;
    levelorderbuild(root);
    int maxlevel = -1;
    Printrightview(root, 0, maxlevel);
    return 0;
}