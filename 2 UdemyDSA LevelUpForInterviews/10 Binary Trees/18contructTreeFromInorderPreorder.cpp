#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
Construct Tree From Inorder & Preorder

Inorder: Left Root Right
Preorder: Root Left Right

- First element of Pre is Root, can start making tree from here 
- Find this root, in inorder
- Left of root is Left Subtree & right is Right Subtree in Inorder
- Now we are done with root, the array which is remaining become subproblem

1. Get element from Preorder
2. Find in Inorder
3. In Inorder: 
        Elements to left are part of left subtree
        Elements to right are part of right subtree
4. Get both orders again, left of Inorder & Preorder, same for Right
5. Repeat

Algorithm:
    - initialize index at 0 in Preorder array, make it root
    - find root position in Inorder
    - In Inorder:
        - Call for root left (start to position-1)
        - Call for root right (position+1 to end)
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

node* solve(vector<int>inorder,vector<int>preorder,int &preIndex,int inStart,int inEnd,int n){
    if(preIndex>=n || inStart>inEnd){
        return NULL;
    }
    int ele=preorder[preIndex++];
    node*root=new node(ele);
    int position=-1;
    for(int i=0;i<n;i++){
        if(inorder[i]==ele){
            position=i;
        }
    }
    root->left=solve(inorder,preorder,preIndex,inStart,position-1,n);
    root->right=solve(inorder,preorder,preIndex,position+1,inEnd,n);
    return root;
}
node*buildTreeInPre(vector<int>inorder,vector<int>preorder,int n){
    int preIndex=0;
    int inStart=0;
    int inEnd=n-1;
    node*ans=solve(inorder,preorder,preIndex,inStart,inEnd,n);
    return ans;
}

// OPTIMIZED
node* solve1(vector<int>inorder,vector<int>preorder,int &preIndex,int inStart,int inEnd,int n,map<int,int>m){
    if(preIndex>=n || inStart>inEnd){
        return NULL;
    }
    int ele=preorder[preIndex++];
    node*root=new node(ele);
    int position=m[ele];
    root->left=solve1(inorder,preorder,preIndex,inStart,position-1,n,m);
    root->right=solve1(inorder,preorder,preIndex,position+1,inEnd,n,m);
    return root;
}
node*buildTreeInPre1(vector<int>inorder,vector<int>preorder,int n){
    int preIndex=0;
    int inStart=0;
    int inEnd=n-1;
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[inorder[i]]=i;
    }
    node*ans=solve1(inorder,preorder,preIndex,inStart,inEnd,n,m);
    return ans;
}


void inorderPrint(node*root){
    if(root==NULL)return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}



int main(){
    

    vector<int>inorder={9,3,15,20,7};
    vector<int>preorder={3,9,20,15,7};
    node*tree=buildTreeInPre(inorder,preorder,5);

    inorderPrint(tree);
    cout<<endl;

    
    node*tree1=buildTreeInPre1(inorder,preorder,5);
    inorderPrint(tree1);
    
    
    return 0;
}