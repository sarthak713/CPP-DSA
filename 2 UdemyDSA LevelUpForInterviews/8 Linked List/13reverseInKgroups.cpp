#include<iostream>
using namespace std;

/*
Reverse in K Groups

Approach:
    - Reverse K starting nodes & recursively reverse others

*/

class node{
public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
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

// Reverse in K groups

node*reverseK(node*&head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*curr=head;
    node*prev=NULL;
    node*next=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=reverseK(curr,k);
    }
    return prev;
}

int main(){
    
    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);
    node*newHead=reverseK(head,3);
    print(newHead);

    
    return 0;
}