//BST program to show the preorder,inorder,postorder traversal 
#include<iostream>
using namespace std;
struct bst_node{
    int data;
    bst_node* left,*right ;
};
//Function to preorder traversal
void preorder(bst_node * root){
    if(root == NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
} 
//Function to inorder traversal
void inorder(bst_node * root){
    if(root == NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
} 
//Function to postorder traversal
void postorder(bst_node * root){
    if(root == NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
} 
bst_node* insert(bst_node* root, int data){
    if(root ==NULL){
       bst_node* node = new bst_node();
       node->data = data;
       node->left =node ->right =NULL;
       root =node;
    }
    else if (data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
     root->right=insert(root->right,data);
     return root;
}
int main(){
bst_node * root = NULL;
root = insert(root,5);
root = insert(root,10);
root = insert(root,15);
root = insert(root,3);
root = insert(root,4);
root = insert(root,1);
cout<<"Data travesal with preorder"<<endl;
preorder(root);
cout<<endl;
cout<<"Data travesal with inorder"<<endl;
inorder(root);
cout<<endl;
cout<<"Data travesal with postorder"<<endl;
postorder(root);
cout<<endl;
}