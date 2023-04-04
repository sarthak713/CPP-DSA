#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(Node*&head,int data){
    Node*n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
}

void insertAtTail(Node*&head,int data){
    Node*n=new Node(data);
    if(head==NULL){
        insertAtHead(head,data);
        return; 
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void deleteHead(Node*&head){
    if(head==NULL){
        return;
    }
    Node*toDel=head;
    head=head->next;
    delete toDel;
}

void deleteAtPosition(Node*&head,int position){
    if(head==NULL){
        return;
    }
    if(position==1){
        deleteHead(head);
        return;
    }
    Node*temp=head;
    int count=1;
    while(count<position-1 && temp->next!=NULL){
        count++;    
        temp=temp->next;
    }
    Node*toDel=temp->next;
    temp->next=temp->next->next;
    delete toDel;
}

void print(Node*head){
    if(head==NULL){
        cout<<"No Element in List: NULL"<<endl;
        return;
    }
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

int main(){
    
    Node*head=new Node(3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);

    deleteAtPosition(head,3);
    deleteAtPosition(head,3);
    deleteAtPosition(head,2);
    deleteAtPosition(head,2);
    deleteAtPosition(head,1);
    print(head);
    
    return 0;
}