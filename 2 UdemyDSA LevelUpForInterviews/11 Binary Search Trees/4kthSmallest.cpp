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

// Find Kth Smallest Element in BST

int solve(node*root,int &i,int k){
    if(root==NULL)return -1;
    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    int right=solve(root->right,i,k);
    return right;
}

int kthsmallest(node*root,int k){
    int i=0;
    return solve(root,i,k);
}

int main(){
    
    
    
    return 0;
}