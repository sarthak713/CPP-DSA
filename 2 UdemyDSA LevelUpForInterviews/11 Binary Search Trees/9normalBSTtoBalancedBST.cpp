#include<iostream>
#include<vector>
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

/*
Normal BST to Balanced BST

- Balanced BST is BST in which height of 2 subtrees of each node differ no more than 1
- absolute (left subtree height - right subtree height) <= 1

1. store inorder of BST
2. now we need to make balanced BST from this Inorder
3. Find mid from inorder
    - left of mid is left subtree
    - right of mid is right subtree
4. make tree using recursion
*/

void inorder(node*root,vector<int>&arr){
    if(root==NULL)return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

node*inorderToBST(int s,int e,vector<int>&arr){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(arr[mid]);
    root->left=inorderToBST(s,mid-1,arr);
    root->right=inorderToBST(mid+1,e,arr);
    return root; 
}

node*balancedBST(node*root){
    if(root==NULL){
        return root;
    }
    vector<int>arr;
    inorder(root,arr);
    return inorderToBST(0,arr.size()-1,arr);
}

int main(){
    
    
    
    return 0;
}