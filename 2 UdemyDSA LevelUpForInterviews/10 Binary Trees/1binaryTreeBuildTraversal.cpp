#include<iostream>
#include<queue>
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

// BUILD TREE

node*buildTree(node*root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

// LEVEL ORDER TRAVERSAL

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

// BUILD FROM LEVEL ORDER TRAVERSAL

void buildFromLevelOrder(node*&root){
    queue<node*>q;
    cout<<"Enter data: ";
    int data; cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<"Enter left for: "<<temp->data<<": ";
        int left; cin>>left;
        if(left!=-1){
            temp->left=new node(left);
            q.push(temp->left);
        }
        cout<<"Enter right for: "<<temp->data<<": ";
        int right; cin>>right;
        if(right!=-1){
            temp->right=new node(right);
            q.push(temp->right);
        }
    }
}


int main(){
    
    node*root=NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root=buildTree(root);
    buildFromLevelOrder(root);
    cout<<"Printing Level Order: "<<endl;
    levelOrderTraversal(root);
    
    return 0;
}