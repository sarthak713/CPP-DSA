#include<iostream>
#include<vector>
#include<algorithm>
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

// Build BST from Preorder Traversal

node*solve(vector<int>&preorder,int mini,int maxi,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    node*root=new node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}

node*buildBST(vector<int>&preorder){
    int n=preorder.size();
    if(n==0){
        return NULL;
    }
    int index=0;
    int mini=INT_MIN;
    int maxi=INT_MAX;
    return solve(preorder,mini,maxi,index);
}

int main(){
    
    
    
    return 0;
}