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

// Right View

void solve(node*root,vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}

vector<int>rightView(node*root){
    vector<int>ans;
    solve(root,ans,0);
    return ans;
}

int main(){
    
    
    
    return 0;
}