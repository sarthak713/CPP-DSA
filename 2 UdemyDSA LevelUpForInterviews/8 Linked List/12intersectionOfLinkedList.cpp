#include<iostream>
#include<map>
using namespace std;

/*
Intersection Point in Linked Lists (Leetcode 160)

Approach 1:
    - traverse 1 list 
    - & for each node of list 1, traverse list 2 from start
    - when nodes are same return ans
    - if no nodes found NULL
Approach 2:
    - use hashmap
Approach 3:
    - take 2 nodes at heads of both Lists
    - keep length of both lists
    - find diff of lengths
    - move long list headNode by this diff
    - then move both by 1 in loop & when they collide
    - return ans
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

// HashMap Approach

node*getIntersectionNode(node *headA, node *headB) {
    if(headA==NULL)return NULL;
    if(headB==NULL)return NULL;
    node*temp=headA;
    map<node*,int>m;
    while(temp!=NULL){
        m.insert({temp,1});
        temp=temp->next;
    }
    temp=headB;
    while(temp!=NULL){
        if(m.find(temp)!=m.end()){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;

}

// Pointers Approach

int lengthList(node*head){
    node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
node *getIntersectionNode(node *head1, node *head2) {
    if(head1==NULL)return NULL;
    if(head2==NULL)return NULL;
    int l1=lengthList(head1);
    int l2=lengthList(head2);
    int diff=0;
    node*temp=NULL;
    node*temp2=NULL;
    if(l1>l2){
        diff=l1-l2;
        temp=head1;
        temp2=head2;
    }else{
        diff=l2-l1;
        temp=head2;
        temp2=head1;
    }
    while(diff>0){
        temp=temp->next;
        diff--;
    }
    while(temp!=NULL && temp2!=NULL){
        if(temp==temp2)return temp;
        temp=temp->next;
        temp2=temp2->next;
    }        
    return NULL;
}

int main(){
    

    
    
    return 0;
}