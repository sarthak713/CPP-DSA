#include<iostream>
using namespace std;

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
    if(head==NULL){
        cout<<"No Element in List: NULL"<<endl;
        return;
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

// Reverse nodes in K Groups
node* kReverse(node*head,int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    int count=1;
    while(curr!=NULL && count<=k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=kReverse(forward,k);
    }
    return prev;
}

int main(){
    
    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    int k=3;
    node*newList=kReverse(head,3);
    print(newList);
    
    return 0;
}