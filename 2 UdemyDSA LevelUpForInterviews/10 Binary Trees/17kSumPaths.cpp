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

// Find Number of path in tree with sum equal to k

void solve(node*root,int k,int&count,vector<int>path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);
    int sum=0;
    for(int i=path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}

int paths(node*root,int k){
    vector<int>path;
    int count=0;
    solve(root,k,count,path);
    return count;
}

int main(){
    
    node*root=new node(10);
    root->left=new node(5);
    root->left->left=new node(3);
    root->left->right=new node(2);
    root->left->right->right=new node(1);
    root->left->left->left=new node(3);
    root->left->left->right=new node(-2);
    root->right=new node(-3);
    root->right->right=new node(11);
    paths(root,8);
    
    return 0;
}