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

// Find Lowest Common Ancestor of 2 Nodes 

node*lca(node*root,node*n1,node*n2){
    if(root==NULL){
        return NULL;
    }
    if(root==n1 || root==n2){
        return root;
    }
    node*left=lca(root->left,n1,n2);
    node*right=lca(root->right,n1,n2);
    if(left==NULL && right==NULL){
        return NULL;
    }
    else if(left!=NULL && right==NULL){
        return left;
    }
    else if(left==NULL && right!=NULL){
        return right;
    }
    return root;
}

int main(){
    
    
    
    return 0;
}