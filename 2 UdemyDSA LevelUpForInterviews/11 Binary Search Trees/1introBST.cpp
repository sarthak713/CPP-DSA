#include<iostream>
#include<queue>
using namespace std;

/*
Binary Search Tree BST

For Every Node:
Root->Left = left is lesser than root
Root->Right = right is bigger than root
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

node* insertIntoBST(node*&root,int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertIntoBST(root->right,data);
    }else{
        root->left=insertIntoBST(root->left,data);
    }
    return root; 
}

void takeInput(node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
void inorder(node*root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node*root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node*root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    
    node*root=NULL;
    cout<<"Enter data for BST: "<<endl;
    takeInput(root);    // 10 8 21 7 27 5 4 3 -1
    cout<<endl;

    cout<<"Printing Level Order: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Inorder: "<<endl;    // Inorder of BST in always Sorted
    inorder(root);
    cout<<endl;
    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder: "<<endl;
    postorder(root);
    cout<<endl;
    
    return 0;
}