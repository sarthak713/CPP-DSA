#include<iostream>
using namespace std;

/*
Flatten Linked List
*/

class node{
    public:
    int data;
    node*next;
    node*bottom;
    node(int val){
        data=val;
        next=NULL;
        bottom=NULL;
    }
};
void insertAtTail(node*&head,int data){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void print(node*head){
    node*temp=head;  
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

// flatten

node*mergeLists(node*left,node*right){
    node*temp=new node(0);
    node*ans=temp;
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->bottom=left;
            temp=temp->bottom;
            left=left->bottom;
        }else{
            temp->bottom=right;
            temp=temp->bottom;
            right=right->bottom;
        }
    }
    while(left!=NULL){
        temp->bottom=left;
        temp=temp->bottom;
        left=left->bottom;
    }
    while(right!=NULL){
        temp->bottom=right;
        temp=temp->bottom;
        right=right->bottom;
    }
    return ans->bottom;
}

node*flatten(node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    head->next=flatten(head->next);
    head=mergeLists(head,head->next);
    return head;
}

int main(){
    
    
    
    return 0;
}