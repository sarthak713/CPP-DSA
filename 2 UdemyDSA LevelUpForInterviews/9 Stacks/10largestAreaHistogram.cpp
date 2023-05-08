#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int>nextSmaller(vector<int>arr,int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>prevSmaller(vector<int>arr,int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=0;i<n;i++){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int largestHistogramRectArea(vector<int>arr){
    int n=arr.size();
    vector<int>prev=prevSmaller(arr,n);
    vector<int>next=nextSmaller(arr,n);
    int maxAns=INT_MIN; 
    for(int i=0;i<n;i++){
        if(next[i]==-1){
            next[i]=n;
        }
        int area=arr[i]*(next[i]-prev[i]-1);
        maxAns=max(maxAns,area);
    } 
    return maxAns;
}

int main(){
    
    vector<int>arr={2,1,5,6,2,3};   
    vector<int>nextArr=nextSmaller(arr,6);   // 1 -1 2 2 -1 -1
    vector<int>prevArr=prevSmaller(arr,6);   //-1 -1 1 5  1  2
    cout<<largestHistogramRectArea(arr)<<endl;
    
    return 0;
}