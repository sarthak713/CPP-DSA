#include<iostream>
using namespace std;

// Deletion in BST

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

// get minimum from BST
node*getMin(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
// get maximum from BST
node*getMax(node*root){
    node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deleteBSTnode(node*&root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
        if(root->left==NULL && root->right==NULL){      // Delete Node with 0 Children
            delete root;    // delete root
            return NULL;    // return null
        }                                               
        if(root->left!=NULL && root->right==NULL){      // Delete Node with 1 Child
            node*temp=root->left;   // store left
            delete root;            // delete root
            return temp;            // return null
        }
        if(root->left==NULL && root->right!=NULL){
            node*temp=root->right;  // store right
            delete root;            // delete root 
            return temp;            // return null
        }
        if(root->left!=NULL && root->right!=NULL){      // Delete Node with 2 Chidren
            // either get min from right or max from left
            node*minValue=getMin(root->right);  // got minimum from right
            root->data=minValue->data;          // copy data in root node
            root->right=deleteBSTnode(root->right,minValue->data);  // delete that min node whose value was copied to root from right
            return root;
        }
    }
    else if(root->data > val){
        root->left=deleteBSTnode(root->left,val);
        return root;
    }
    else{
        root->right=deleteBSTnode(root->right,val);
        return root;
    }
    return root;
}

int main(){
    
    
    
    return 0;
}