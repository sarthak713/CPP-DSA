#include<iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int>&s,int ele){
    if(s.empty() || (!s.empty() && s.top()<=ele)){
        s.push(ele);
        return;
    }
    int top=s.top();
    s.pop();
    sortInsert(s,ele);
    s.push(top);
}

void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    sortStack(s);
    sortInsert(s,top);
}

int main(){
    
    stack<int>s;
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(2);
    s.push(3);
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}