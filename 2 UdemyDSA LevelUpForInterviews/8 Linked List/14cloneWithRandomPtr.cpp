#include<iostream>
#include<unordered_map>
using namespace std;

/*
Clone Linked List with Next & Random Pointers

Question:
    - List structure has been modified
    - we have: Node data, next ptr, random ptr (points to any list node)
    - We have to clone this list
    Example:
    Next = 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Random 3    1    5    3    2

Approach 1:
    - make clone linked list with next pointers of original list
    - Now we have to make random pointers
    - traverse each original linked list and find out how far is its node's random pointer
    - make random pointer of clone list, using 2 loops
    T.C. = O(n^2)

Approach 2:
    - create clone list using next ptr of original list
    - Create Random pointers:
        - Make a Hashmap <original node,clone node>
        - Mapping of all nodes of original node are mapped with same clone list nodes
        - Now we have to assign Clone node Random pointer
            To reach Clone node's Random, 
            we have to go to Original node, 
            then to its Random & then to its Mapped Value
            Which sends us to Clone Node's Random
        - Clone Node->Random = mapping[Original Node->Random]
*/

class Node{
public:
    int data;
    Node*next;
    Node*random;
    Node(int val){
        data=val;
        next=NULL;
        random=NULL;
    }
};
void insertAtTail(Node*&head,int data){
    Node*n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void print(Node*head){
    Node*temp=head;  
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

// Clone List

Node*cloneList(Node*head){
    Node*clone=new Node(head->data);
    Node*temp1=head;
    Node*temp2=clone;
    unordered_map<Node*,Node*>m;
    m.insert({head,clone});
    temp1=temp1->next;
    while(temp1!=NULL){
        insertAtTail(clone,temp1->data);
        temp2=temp2->next;
        m.insert({temp1,temp2});
        temp1=temp1->next;
    }
    temp1=head;
    temp2=clone;
    while(temp2!=NULL){
        temp2->random=m[temp1->random];
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return clone;
}

int main(){
    

    
    
    return 0;
}