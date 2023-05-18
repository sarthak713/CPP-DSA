#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Find LCA in BST

node*lcaBST(node*root,node*n1,node*n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data < n1->data && root->data < n2->data){
        return lcaBST(root->right,n1,n2);
    }
    if(root->data > n1->data && root->data > n2->data){
        return lcaBST(root->left,n1,n2);
    }
    return root;
}

node*lcaBSTIterative(node*root,node*n1,node*n2){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        if(root->data < n1->data && root->data < n2->data){
            root=root->right;
        }
        else if(root->data < n1->data && root->data < n2->data){
            root=root->left;
        }
        else{
            return root;
        }
    }
    return root;
}

int main(){
    
    
    
    return 0;
}