#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
Construct Tree From Inorder & Postorder
*/

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

node* solve(vector<int>& inorder, vector<int>& postorder,int &postIndex,int inStart,int inEnd,int n){
    if(postIndex<0 || inStart>inEnd){
        return NULL;
    }
    int ele=postorder[postIndex--];
    node*root=new node(ele);
    int position=-1;
    for(int i=0;i<n;i++){
        if(inorder[i]==ele){
            position=i;
        }
    }
    root->right=solve(inorder,postorder,postIndex,position+1,inEnd,n);
    root->left=solve(inorder,postorder,postIndex,inStart,position-1,n);
    return root;
}
node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=inorder.size();
    int postIndex=n-1;
    int inStart=0;
    int inEnd=n-1;
    return solve(inorder,postorder,postIndex,inStart,inEnd,n);
}


int main(){
    
    return 0;
}