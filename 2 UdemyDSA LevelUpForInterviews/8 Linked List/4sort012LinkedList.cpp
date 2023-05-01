#include<iostream>
using namespace std;

/*
Sort 0,1,2 in Linked List

Approach 1:
    - count number of 0, 1, 2
    - traverse list again and replace values according to count

Approach 2:
    - Data Replacement not allowed, change pointers
    - Make 3 linked lists, and merge all

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

// Sort 0 1 2
node*sortList(node*head){
    node*zeoHead=new node(-1);
    node*zeoTail=zeoHead;
    node*oneHead=new node(-1);
    node*oneTail=oneHead;
    node*twoHead=new node(-1);
    node*twoTail=twoHead;
    node*temp=head;
    while(temp!=NULL){
        int val=temp->data;
        if(val==0){
            zeoTail->next=temp;
            zeoTail=temp;
        }
        else if(val==1){
            oneTail->next=temp;
            oneTail=temp;
        }
        else{
            twoTail->next=temp;
            twoTail=temp;
        }
        temp=temp->next;
    }
    if(oneHead->next!=NULL){
        zeoTail->next=oneHead->next;
    }else{
        zeoTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zeoHead->next;
    delete zeoHead;
    delete oneHead;
    delete twoHead;
    return head;
}

int main(){
    
    node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,2);
    print(head);
    
    
    return 0;
}