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

// find kth ancestor of node in Binary Tree

node*solve(node*root,int &k,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    node*left=solve(root->left,k,node);
    node*right=solve(root->right,k,node);
    if(left!=NULL && right==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return left;
    }
    if(left==NULL && right!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int kthAncestor(node*root,int k,int node){
    node*ans=solve(root,k,node);
    if(ans==NULL)return -1;
    return ans->data;
}

int main(){
    
    
    
    return 0;
}