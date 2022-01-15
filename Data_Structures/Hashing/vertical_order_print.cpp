#include <iostream>
#include <map>
#include <vector>
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
        left = right = NULL;
    }
};

void verticalorderprint(map<int, vector<int>> &m, int d, node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // otherwise
    m[d].push_back(root->data);
    verticalorderprint(m, d - 1, root->left);
    verticalorderprint(m, d + 1, root->right);
    return;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    root->left->right = new node(6);
    root->right->left = new node(7);
    root->right->right->right = new node(8);
    root->left->right->right = new node(9);

    map<int, vector<int>> m;
    int d = 0;
    verticalorderprint(m, d, root);
    for (auto s : m)
    {
        cout << s.first << "->";
        for (auto p : s.second)
        {
            cout << p << ",";
        }
        cout << endl;
    }
    return 0;
}