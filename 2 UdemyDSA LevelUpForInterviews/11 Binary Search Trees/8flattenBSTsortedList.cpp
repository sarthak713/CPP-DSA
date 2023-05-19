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
Flatten BST into Sorted Linked List
    - point left to NULL
    - point right to next node
BST inorder is sorted
    1. store inorder in vector<node*> 
       so we have access to left & right pointers 
    2. start with i=0 till i=n-2
    3. point left of each node to null & right to next node in arr
    4. when out of loop, point left & right of last node to NULL
*/

void inorder(node*root,vector<node*>&arr){
    if(root==NULL)return;
    inorder(root->left,arr);
    arr.push_back(root);
    inorder(root->right,arr);
}

node*flatten(node*root){
    if(root==NULL){
        return root;
    }
    vector<node*>arr;
    inorder(root,arr); 
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        arr[i]->left=NULL;
        arr[i]->right=arr[i+1];
    }
    arr[n-1]->left=NULL;
    arr[n-1]->right=NULL;
    return arr[0];
}

int main(){



    return 0;
}