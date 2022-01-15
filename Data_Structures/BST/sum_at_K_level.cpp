#include<iostream>
using namespace std ;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data= d;
        left=NULL;
        right=NULL:
    }
};

node*buildtree()
{
    int d;
    int noc;
    cin>>d;
    insertintree(d);
    return root;
}

int main(){
    node*root=NULL;
    root=buildtree();
    return 0;
}