#include<iostream>
using namespace std;

/*
Validate BST

1. For each node, left is small & right is big
2. Inorder traversal of BST is sorted
*/

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

bool isBST(node*root,int min,int max){
    if(root==NULL)return true;
    if(root->data > min && root->data < max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left&&right;
    }
    else{
        return false;
    }
}
bool isValidBST(node*root){
    return isBST(root,INT_MIN,INT_MAX);
}

int main(){
    
    
    
    return 0;
}