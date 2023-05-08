#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int>reverseQ(queue<int>&q,int k){
    int n=q.size();
    stack<int>s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main(){
    
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int>rev=reverseQ(q,3);
    while(!rev.empty())cout<<rev.front()<<endl,rev.pop();
    
    return 0;
}