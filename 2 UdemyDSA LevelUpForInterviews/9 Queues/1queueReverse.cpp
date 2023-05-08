#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void rev(queue<int>&q){
    if(q.empty()){
        return;
    }
    int top=q.front();
    q.pop();
    rev(q);
    q.push(top);
}

queue<int>reverseQ(queue<int>&q){
    rev(q);
    return q;
}

int main(){
    
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    queue<int>rev=reverseQ(q);
    while(!rev.empty())cout<<rev.front()<<endl,rev.pop();
    
    return 0;
}