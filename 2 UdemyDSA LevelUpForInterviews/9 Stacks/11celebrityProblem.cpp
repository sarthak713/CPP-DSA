#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int>>arr,int n){
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()!=1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(arr[a][b]==1){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int ele=s.top();
    for(int i=0;i<n;i++){
        if(i!=ele && arr[ele][i]==1){
            return -1;
        }
        if(i!=ele && arr[i][ele]==0){
            return -1;
        }
    }
    return ele;
}

int main(){
    
    vector<vector<int>>arr=
    {{0,1,0},
     {0,0,0},
     {0,1,0}};
    int n=3;
    cout<<celebrity(arr,n)<<endl;
    
    return 0;
}