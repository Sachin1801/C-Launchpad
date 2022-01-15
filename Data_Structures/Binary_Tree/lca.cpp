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

node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a or root->data == b)
    {
        return root;
    }
    node *leftans = lca(root->left, a, b);
    node *rightans = lca(root->right, a, b);
    if (leftans != NULL and rightans != NULL)
    {
        return root;
    }
    if (leftans != NULL)
    {
        return leftans;
    }
    return rightans;
}

class Pair
{
public:
    int branchsum;
    int maxSum;
    Pair()
    {
        branchsum = 0;
        maxSum = 0;
    }
};

Pair maxsumPath(node *root)
{
    Pair p;
    if (root == NULL)
    {
        return p;
    }
    Pair left = maxsumPath(root->left);
    Pair right = maxsumPath(root->right);

    //construct two values
    int op1 = root->data;
    int op2 = left.branchsum + root->data;
    int op3 = right.branchsum + root->data;
    int op4 = left.branchsum + right.branchsum + root->data;

    int current_ans_from_root = max(op1, max(op2, max(op3, op4)));

    //branch sum of the current root
    p.branchsum = max(left.branchsum, max(right.branchsum, 0)) + root->data; // 0 is taken if both the left branch and right branch have branchsum as 0 then we take the root node only and doesn't include the right or the left branch
    p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_from_root));
    return p;
}

int search(node *root, int key, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return level;
    }
    int left = search(root->left, key, level + 1);
    if (left != -1)
    {
        return left;
    }
    return search(root->right, key, level + 1);
}

int finddistance(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);
    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);
    return l2 + l1;
}

int main()
{
    node *root = buildtree();
    // node *ans1 = lca(root, 4, 7);
    // cout << ans1->data << endl;
    // node *ans2 = lca(root, 6, 9);
    // cout << ans2->data << endl;
    cout << "Max sum path " << maxsumPath(root).maxSum << endl;

    return 0;
}