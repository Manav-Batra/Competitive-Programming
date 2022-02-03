// IMPLEMENTATION OF TREES
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct  node *left,*right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=new node;
    cout<<"Enter data"<<endl;
    cin>>x;
    if(x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    cout<<"Enter Left Child "<<x<<endl;
    newnode->left=create();
    cout<<"Enter Right Child "<<x<<endl;
    newnode->right=create();
    return newnode;

}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    struct node *root;
    root=create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}