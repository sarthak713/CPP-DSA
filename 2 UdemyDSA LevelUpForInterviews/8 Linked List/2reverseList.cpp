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

//-------------APPROACH 1-----------
Node*iterativeReverseLL(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*prev=NULL;
    Node*curr=head;
    Node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

//-------------APPROACH 2-----------
void solveRecursive(Node*&head,Node*curr,Node*prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node*forward=curr->next;
    solveRecursive(head,forward,curr);
    curr->next=prev;
}
Node* recursiveReverseLL(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*curr=head;
    Node*prev=NULL;
    solveRecursive(head,curr,prev);
    return head;
}

//-------------APPROACH 3-----------
Node*reverseLL(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*small=reverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return small;
}

int main(){
    
    Node*head=new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);

    Node*reversedList = iterativeReverseLL(head);
    print(reversedList);
    Node*reversedList1 = recursiveReverseLL(reversedList);
    print(reversedList1);
    Node*reverse3=reverseLL(reversedList1);
    print(reverse3);
    
    return 0;
}