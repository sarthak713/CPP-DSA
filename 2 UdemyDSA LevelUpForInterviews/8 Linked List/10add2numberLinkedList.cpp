#include<iostream>
using namespace std;

/*
Add 2 Numbers Represented By Linked List

Approach:
    - reverse both lists
    - add from left only
    - reverse answer list
    - while adding,
        - find sum of both nodes, sum=data of nodes+carry
        - take carry=0
        - find lastDigit=sum%10
        - carry=sum/10
        - put lastDigit as node, repeat
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

// add numbers as linked list

node*reverseList(node*head){
    node*curr=head;
    node*next=NULL;
    node*prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
// FIRST WAY
node*addList(node*head1,node*head2){
    node*ans=NULL;
    int sum=0;
    int carry=0;
    int digit=0;
    while(head1!=NULL && head2!=NULL){
        sum=carry+head1->data+head2->data;
        digit=sum%10;
        carry=sum/10;
        insertAtTail(ans,digit);
        head1=head1->next;
        head2=head2->next;
    }
    while(head1!=NULL){
        sum=carry+head1->data;
        digit=sum%10;
        carry=sum/10;
        insertAtTail(ans,digit);
        head1=head1->next;
    }
    while(head2!=NULL){
        sum=carry+head2->data;
        digit=sum%10;
        carry=sum/10;
        insertAtTail(ans,digit);
        head2=head2->next;
    }
    insertAtTail(ans,carry);
    return ans;
}
node*addTwoLists(node*head1,node*head2){
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    head1=reverseList(head1);
    head2=reverseList(head2);
    node*ans=addList(head1,head2);
    ans=reverseList(ans);
    return ans;
}

int main(){
    
    node*head1=new node(9);
    insertAtTail(head1,9);
    insertAtTail(head1,9);
    node*head2=new node(9);
    insertAtTail(head2,9);
    insertAtTail(head2,9);
    node*sum1=addTwoLists(head1,head2);
    print(sum1);         

    
    return 0;
}