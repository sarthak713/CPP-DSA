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

pair<bool,int>isSum(node*root){
    if(root==NULL){
        return {true,0};
    }
    if(root->left==NULL && root->right==NULL){
        return {true,root->data};
    }
    pair<bool,int>left=isSum(root->left);
    pair<bool,int>right=isSum(root->right);
    bool isLeft=left.first;
    bool isRight=right.first;
    bool isSum=(root->data==left.second+right.second);
    pair<bool,int>ans;
    ans.first=(isSum && isLeft && isRight);
    ans.second=root->data+left.second+right.second;
    return ans;
}

bool isSumTree(node*root){
    if(root==NULL){
        return true;
    }
    isSum(root).first;
}

int main(){
    
    
    
    return 0;
}