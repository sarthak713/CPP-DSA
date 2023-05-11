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

// Hiegth Of Binary Tree
int heightOfTree(node*root){
    if(root==NULL){
        return 0;
    }
    int left=heightOfTree(root->left);
    int right=heightOfTree(root->right);
    return max(left,right)+1;
}

// Diameter Of Binary Tree
int diameterOfTree(node*root){
    if(root==NULL){
        return 0;
    }
    int left=diameterOfTree(root->left);
    int right=diameterOfTree(root->right);
    int combo=heightOfTree(root->left)+heightOfTree(root->right)+1;
    return max(combo,max(left,right));
}

// Diameter Optimized
pair<int,int>diameter(node*root){
    if(root==NULL){
        return {0,0};
    }
    pair<int,int>left=diameter(root->left);
    pair<int,int>right=diameter(root->right);
    int leftDiameter=left.first;
    int rightDiameter=right.first;
    int combo=left.second+right.second+1;
    pair<int,int>ans;
    ans.first=max(combo,max(leftDiameter,rightDiameter));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameterOfBinaryTree(node* root) {
    if(root==NULL){
        return 0;
    }
    return diameter(root).first-1;
}


int main(){
    
    
    
    return 0;
}