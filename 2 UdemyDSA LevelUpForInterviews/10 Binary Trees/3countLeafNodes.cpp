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

void inorder(node*root,int &count){
    if(root==NULL){
        return;
    }
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}

int leafNodes(node*root){
    int count=0;
    inorder(root,count);
    return count;
}

int main(){
    
    
    
    return 0;
}