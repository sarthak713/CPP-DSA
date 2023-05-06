#include<iostream>
#include<stack>
using namespace std;

void deleteSolve(stack<int>&s,int count,int n){
    if(count==n/2){
        s.pop();
        return;
    }
    int top=s.top();
    s.pop();
    deleteSolve(s,count+1,n);
    s.push(top);
}
void deleteMiddle(stack<int>&s, int n){
    int count=0;
    deleteSolve(s,count,n);
}

int main(){
    
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int n=4;
    deleteMiddle(s,n);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}