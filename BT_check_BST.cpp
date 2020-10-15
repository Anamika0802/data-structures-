//To Check a given binary tree  if it is a binary search tree
#include<iostream>
#include<climits>
using namespace std;
struct tree_node{
    int data;
    tree_node* left,*right ;
};
//Function to check the tree is BST or not((returns true if the tree is BST)
bool isBST(tree_node* node,int min,int max){
    if(node== NULL)
    return true;
    if(node->data<min || node->data >max)
    return false;
    return isBST(node->left,min,node->data) && isBST(node->right,node->data+1,max);
}
tree_node* insert(tree_node* current, int data){
    if(current ==NULL){
       tree_node* node = new tree_node();
       node->data = data;
       node->left =node ->right =NULL;
       current =node;
    }
    return current;
}
int main(){
tree_node * root = NULL;
root = insert(root,4);
root->left = insert(root->left,2);
root->right = insert(root->right,5);
root->left->left = insert(root->left->left,1);
root->left->right = insert(root->left->right,3);
if(isBST(root,INT_MIN,INT_MAX))cout<<"Tree is BST"<<endl;
else cout<<"Tree is not BST"<<endl;
}