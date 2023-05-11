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

// Balanced Tree
// diff of height of left & right subtree <= 1 for all nodes

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
bool isBalancedTree(node*root){
    if(root==NULL){
        return true;
    }
    bool left=isBalancedTree(root->left);
    bool right=isBalancedTree(root->right);
    int diff=abs(height(root->left)-height(root->right));
    int isBal=(diff<=1);
    return left&&right&&isBal;
}

// Optimized

pair<bool,int> balance(node*root){
    if(root==NULL){
        return {true,0};
    }
    pair<bool,int>left=balance(root->left);
    pair<bool,int>right=balance(root->right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    ans.first=(leftAns && rightAns && diff);
    ans.second=max(left.second,right.second)+1;
    return ans;
}
bool isBalanced(node* root) {
    if(root==NULL){
        return true;
    }
    return balance(root).first;
}

int main(){
    
    
    
    return 0;
}