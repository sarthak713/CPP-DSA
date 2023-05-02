#include<iostream>
using namespace std;

/*
Rotate Linked List By K Places

Input=1,2,3,4,5 -  K=2
Output= 4,5,1,2,3
    - Rotate 1: 5,1,2,3,4
    - Rotate 2: 4,5,1,2,3

Approach 1:
    - traverse to node before end
    - make end head 
    - and next of node before end null
    - T.C. = O(n*k), as we have to traverse to end k times
Approach 2:
    - There can be 2 cases:
        - k < length
        - k >= length
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

// Rotate

int listLength(node*head){
    node*temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node*rotate(node*&head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    int length=listLength(head);
    if(k>=length){
        k=k%length;
    }
    while(k>0){
        node*temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node*forward=temp->next;
        temp->next=NULL;
        forward->next=head;
        head=forward;
        k--;
    }
    return head;
}

int main(){
    
    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);
    node*newHead=rotate(head,2);
    print(newHead);
    
    return 0;
}