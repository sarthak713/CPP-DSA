#include<iostream>
using namespace std;

/*
Merge Sort In Linked List

Approach:
    - No Data Replacement, Change Links
    - split into 2 lists using mid
    - sort left & right half using recursion
    - apply merge 2 sorted lists approach for left & right half
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

// Merge Sort

node*getMid(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node*merge(node*&first,node*&second){
    if(first==NULL)return second;
    if(second==NULL)return first;
    node*ans=new node(-1);
    node*temp=ans;
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            temp->next=first;
            temp=first;
            first=first->next;
        }else{
            temp->next=second;
            temp=second;
            second=second->next;
        }
    }
    while(first!=NULL){
        temp->next=first;
        temp=first;
        first=first->next;
    }
    while(second!=NULL){
        temp->next=second;
        temp=second;
        second=second->next;
    }
    ans=ans->next;
    return ans;
}

node*mergeSort(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    // find mid
    node*mid=getMid(head);
    // break list in 2 halves
    node*left=head;
    node*righ=mid->next;
    mid->next=NULL;
    // recursive sort
    left=mergeSort(left);
    righ=mergeSort(righ);
    // merge both halves
    node*ans=merge(left,righ);
    return ans;
}

int main(){
    
    node*head=new node(6);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,9);
    insertAtTail(head,8);
    insertAtTail(head,4);
    print(head);
    node*ans=mergeSort(head);
    print(ans);
    
    return 0;
}