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

// Two Sum in BST

void inorder(node*root,vector<int>&arr){
    if(root==NULL)return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
bool findTarget(node* root, int k) {
    if(root==NULL)return false;
    vector<int>arr;
    inorder(root,arr);
    int l=0;
    int r=arr.size()-1;
    int sum=0;
    while(l<r){
        sum=arr[l]+arr[r];
        if(sum==k){
            return true;
        }
        else if(sum<k){
            l++;
        }
        else{
            r--;
        }
    }
    return false;
}

int main(){
    
    
    
    return 0;
}