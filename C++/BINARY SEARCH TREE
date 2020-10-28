#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* temp(int data){
    node* temp=new node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
node* insert(node* root,int data)
{
if(root==NULL)
{
    root=temp(data);
}
else if(data<=root->data){
    root->left=insert(root->left,data);
}
else
{
    root->right=insert(root->right,data);


}
    return root;
}
