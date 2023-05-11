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

// Boundary Traversal
// Left Part -> Leaf Node -> Right Part

void leftPart(vector<int>&ans,node*root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        leftPart(ans,root->left);
    }else{
        leftPart(ans,root->right);
    }
}
void rightPart(vector<int>&ans,node*root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right){
        rightPart(ans,root->right);
    }else{
        rightPart(ans,root->left);
    }
    ans.push_back(root->data);
}
void leaves(vector<int>&ans,node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    leaves(ans,root->left);
    leaves(ans,root->right);
}

vector<int> boundaryTraversal(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    leftPart(ans,root->left);
    leaves(ans,root->left);
    leaves(ans,root->right);
    rightPart(ans,root->right);
    return ans;
}

int main(){

/*
            1
        2       3
    4      5        6
7     8      9          10
*/

    node*root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->left->left=new node(7);
    root->left->left->right=new node(8);
    root->left->right=new node(5);
    root->left->right->right=new node(9);
    root->right=new node(3);
    root->right->right=new node(6);
    root->right->right->right=new node(10);
    vector<int>boundary=boundaryTraversal(root);
    for(auto i:boundary)cout<<i<<" ";
    cout<<endl;

    return 0;
}