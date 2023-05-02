#include<iostream>
using namespace std;

/*
Check For Palindromic List

Approach:
    - find middle
    - reverse list from middle->next
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

// Check for Palindromic List
node*reverseList(node*&head){
    node*curr=head;
    node*prev=NULL;
    node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
node*getMid(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
bool isPalindrome(node*head){
    if(head->next==NULL){
        return true;
    }
    node*mid=getMid(head);
    node*temp=mid->next;
    mid->next=reverseList(temp);
    node*head1=head;
    node*head2=mid->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}


int main(){
    
    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    print(head);
    cout<<isPalindrome(head)<<endl;
    print(head);
    
    return 0;
}