#include<iostream>
using namespace std;

// Sum of Nodes of Longest Path From Root to Leaf

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

void solve(node*root,int sum,int &maxSum,int len,int &maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }
        else if(len==maxLen){
            maxSum=max(sum,maxSum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}

int sumOfLongestPath(node*root){
    int len=0;
    int maxLen=0;
    int sum=0;
    int maxSum=INT_MIN;
    solve(root,sum,maxSum,len,maxLen);
    return maxSum;
}

int main(){
    
    
    
    return 0;
}