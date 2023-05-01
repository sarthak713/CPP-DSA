#include<iostream>
using namespace std;

/*
Merge 2 sorted Linked Lists

Approach:
    -  take 2 pointers in one list, prev & curr
    - check if element of second list can come in between prev-curr
    - change pointers
    - go to next node in second list & update first list pointer
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
void insertAtHead(node*&head,int data){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
}
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

// Merge 2 sorted linked lists
node* solve(node*first,node*second){
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    node*curr1=first;
    node*next1=curr1->next;
    node*curr2=second;
    node*next2=curr2->next;
    while(next1!=NULL && curr2!=NULL){
        if(curr2->data>=curr1->data && curr2->data<=next1->data){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }else{
            curr1=next1;
            next1=curr1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return first;
            }
        }
    }
    return first;
}
node*sortLists(node*first,node*second){
    if(first==NULL)return second;
    if(second==NULL)return first;
    if(first->data<=second->data){
        return solve(first,second);
    }
    return solve(second,first);
}


int main(){
    
    node*first=new node(1);
    insertAtTail(first,4);
    insertAtTail(first,6);
    insertAtTail(first,9);
    node*second=new node(2);
    insertAtTail(second,3);
    insertAtTail(second,5);
    insertAtTail(second,6);
    insertAtTail(second,10);
    print(first);
    print(second);

    node*sorted=sortLists(first,second);
    print(sorted);
    
    return 0;
}