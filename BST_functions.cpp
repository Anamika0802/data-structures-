//Binary Search Tree - Implementation
//to creat a BST and search a element in it,delete a element,to find minimum, to find maximum
#include<iostream>
using namespace std;
struct bst_node{
    int data;
    bst_node* left,*right ;
};
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
//Function to Delete a element from BST
//Function to find the minimum in the subtree
bst_node* Find_min(bst_node * temp){
    while(temp ->left!=NULL)temp=temp->left;
    return temp;
}
bst_node* Delete(bst_node* node, int data){
    if(node ==NULL)return node;
    else if (data< node->data)node->left = Delete(node->left,data);
    else if(data> node->data)node->right = Delete(node->right,data);//till here the code is to find the element
    else{
        //Case 1: no child
        if (node->left==NULL && node->right ==NULL)
        {
            delete node;
            node= NULL;
        }
        //case 2: one child
        else if (node->left==NULL)
        {
            bst_node* t= node;
            node =node->right;
            delete t;
        }
        else if (node->right==NULL)
        {
            bst_node* t= node;
            node =node->left;
            delete t;
        }
        //Case 3: two children
        else
        {
            bst_node* t= Find_min(node->right);
            node->data = t->data;
            node->right = Delete(node->right,t->data);
        }
    }
    return node;
}
//Funtion to search a element in BST
bool search(bst_node *root, int data){
    if(root ==NULL)
    return false;
    else if(root->data==data)
    return true;
    else if(data <root->data)
    return search(root->left,data);
    else
    return search(root->right,data);
}
//To Find the Minimum Element
int minimum(bst_node* root){
    bst_node* t = root;
    if(t=NULL)return NULL;
    while (t->left != NULL)
    {
        t = t->left;
    }
    return t->data;
}
//To Find the Maximum Element
int maximum(bst_node* root){
    bst_node* t = root;
    if(t=NULL)return NULL;
    while (t->right != NULL)
    {
        t = t->right;
    }
    return t->data;
}
//To Find the Height
int height(bst_node* root){
    if (root ==NULL)
    return -1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return max(left_height, right_height)+1;
}
//Function to inorder traversal
void inorder(bst_node * root){
    if(root == NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
} 
int main(){
bst_node * root = NULL;
root = insert(root,5);
root = insert(root,10);
root = insert(root,15);
root = insert(root,3);
root = insert(root,4);
root = insert(root,1);
int n;
 cout<<"Enter a number to be searched : "<<endl;
 cin>>n;
 if(search(root,n))
 cout<<"Found"<<endl;
 else
 cout<<"Not Found! "<<endl;

 cout<<"Maximum number in tree is : "<<maximum(root)<<endl;
 cout<<"Minimum number in tree is : "<<minimum(root)<<endl;
 cout<<"Height of tree is : "<<height(root)<<endl;

cout<<"Tree in Inorder : "<<endl;
 inorder(root);
 cout<<endl;
 root= Delete(root,10);
 cout<<"Tree in Inorder : "<<endl;
 inorder(root);
 cout<<endl;
}