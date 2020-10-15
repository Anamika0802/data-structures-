//To find inorder succesor of the BST 
#include<iostream>
using namespace std;
struct bst_node{
    int data;
    bst_node* left,*right ;
};
// Function to find some data in tree
bst_node* find(bst_node* root, int data){
    if(root ==NULL)
    return NULL;
    else if(root->data==data)
    return root;
    else if(data <root->data)
    return find(root->left,data);
    else
    return find(root->right,data);
}
//Function to find the minimum in the tree
bst_node* Find_min(bst_node * temp){
    if(temp=NULL)return NULL;
    while(temp ->left!=NULL)temp=temp->left;
    return temp;
}
//Function to get the succesor 
bst_node* successor(bst_node * root , int data){
bst_node * current = find(root,data);
if(current ==NULL)return NULL;
//case 1: node has right subtree
if (current->right != NULL)
return Find_min(current->right);
//case 2: node  does not has right subtree
else
{
    bst_node* suc = NULL, *ancestor = root;
    while (ancestor!= current)
    {
        if(current->data< ancestor ->data){
            suc = ancestor;
            ancestor = ancestor->left;
        }
        else ancestor = ancestor->right;
    }
    return suc;
}
}
//Function to inorder traversal
void inorder(bst_node * root){
    if(root == NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
} 
// Function to insert a new node
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
cout<<"Tree in Inorder : "<<endl;
 inorder(root);
 cout<<endl;
 bst_node* suc = successor(root,4);
 if(suc == NULL)cout<<"NO Successor found! \n";
 else cout<<"Successor is "<<suc->data<<endl;
}