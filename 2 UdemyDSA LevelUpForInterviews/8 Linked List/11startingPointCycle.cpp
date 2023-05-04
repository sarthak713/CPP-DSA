#include<iostream>
using namespace std;


/*
Find Starting Point of Cycle

Approach 1:
    - use hash map to store nodes & frequency when visited
    - if hashmap contains node before, then it is ans
    - if null is reached then no cycle present
    - T.C. = O(n), S.C. = O(n)

Approach 2:
    - use slow & fast pointer method
    - initialize both at head
    - Find collision point
        - move slow by 1, fast by 2 steps
        - till they collide
    - make one more start pointer, initiall at head
        - move slow & start by 1 step
        - when they collide, it is starting of linked list cycle
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

node*cycleNode(node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head;
    node*start=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(start!=slow){
                start=start->next;
                slow=slow->next;
            }
            return start;
        }
    }
    return NULL;
}


int main(){
    
    node*head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=head->next->next;
    cout<<cycleNode(head)->data<<endl;

    return 0;
}