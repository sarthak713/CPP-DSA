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

// Find Inorder Predecessor & Successor Of Node in BST

pair<int,int>findBoth(node*root,int key){
    node*temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){
        if(temp->data < key){
            pred=temp->data;
            temp=temp->right;
        }
        else{
            succ=temp->data;
            temp=temp->left;
        }
    }
    node*leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    node*rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    return {pred,succ};
}

int main(){
    
    
    
    return 0;
}