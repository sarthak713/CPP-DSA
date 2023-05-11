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

// Check if 2 trees are identical or not

bool isSameTree(node*root1,node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }
    bool isLeft=isSameTree(root1->left,root2->left);
    bool isRight=isSameTree(root1->right,root2->right);
    bool values=(root1->data==root2->data);
    return isLeft && isRight && values;
}



int main(){
    
    
    
    return 0;
}