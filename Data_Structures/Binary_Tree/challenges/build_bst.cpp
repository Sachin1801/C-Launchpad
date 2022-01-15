#include <iostream>
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

node *buildbst(int arr[], int s, int e)
{

    if (s > e)
    {
        return NULL;
    }
    //Get the middle element and make it root
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildbst(arr, 0, mid - 1);
    root->right = buildbst(arr, mid + 1, e);
    return root;
}

void printtree(node *root)
{
    //base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printtree(root->left);
    printtree(root->right);
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        node *root = buildbst(a, 0, n - 1);
        printtree(root);
        cout << endl;
    }
    return 0;
}