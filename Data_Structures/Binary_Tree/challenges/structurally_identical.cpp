#include <iostream>
using namespace std;

class node
{
public:
    char data;
    node *left;
    node *right;
    node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildtree()
{
    char d;
    if (d == "false")
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

int main()
{
    node *tree1 = buildtree();
    node *tree2 = buildtree();
    bfs(tree1);
    cout << endl;
    bfs(tree2);
    if (compare_trees(tree1, tree2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}