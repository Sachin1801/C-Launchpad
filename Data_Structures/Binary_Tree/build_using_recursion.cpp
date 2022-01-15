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

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //otherwise start printing the root and then the subtrees(children) from the left size of the tree first the left branches and then the right
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void printIn(node *root)
{
    if (root == NULL)
    {
        return;
    }
    //print the left then the root and then the right
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void postprint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // print the left then the right and then the root
    postprint(root->left);
    postprint(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    //base case
    if (root == NULL)
    {
        return 0;
    }
    //recursive case - calculate the height of the left part and the right part aqnd then return the max of lest side, right side +1
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
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

void printAllLevels(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
    return;
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

// void Printapp1(node *root)
// {
//     queue<pair<node *, int>> q;
//     int l = height(root);
//     q.push(root,l);
//     while(!q.empty())
//     {
//         node* f= q.front().first;
//         if(q.front().second<l)
//         {
//             cout<<endl;
//         }
//         cout<<f->data<<" ";
//         q.pop();
//         q.push(f->left,l-1);

//     }
// }

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int sumofnodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumofnodes(root->left) + sumofnodes(root->right);
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    //otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

int replacesum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    //recursive case
    int leftsum = replacesum(root->left);
    int rightsum = replacesum(root->right);
    int temp = root->data;
    root->data = leftsum + rightsum;
    return temp + root->data;
}

class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(node *root)
{
    HBPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }
    //recursive case
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height + right.height) <= 1 && left.balance && right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }
    return p;
}

node *buildTreeFromArray(int *a, int s, int e)
{
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Recursive Case
    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildTreeFromArray(a, s, mid - 1);
    root->right = buildTreeFromArray(a, mid + 1, e);
    return root;
}

int main()
{
    // node *root = buildtree();
    // // print(root);
    // // cout << endl;
    // // printIn(root);
    // // cout << endl;
    // // postprint(root);
    // // cout << endl;
    // // cout << height(root) << endl;
    // // printAllLevels(root);
    // // bfs(root);
    // // cout << count(root) << endl;
    // // cout << sumofnodes(root) << endl;
    // // Pair p = fastDiameter(root);
    // // cout << p.height << endl;
    // // cout << p.diameter << endl;
    // bfs(root);
    // cout << endl;
    // // replacesum(root);
    // // bfs(root);
    // // cout << endl;
    // if (isHeightBalanced(root).balance)
    // {
    //     cout << "Balanced Tree" << endl;
    // }
    // else
    // {
    //     cout << "Not A balanced tree" << endl;
    // }
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    node *root = buildTreeFromArray(a, 0, n - 1);
    bfs(root);
    cout << endl;
    return 0;
}