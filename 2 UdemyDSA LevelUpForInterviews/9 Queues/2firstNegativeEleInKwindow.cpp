#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int>negativeNums(vector<int>arr,int k){
    int n=arr.size();
    vector<int>ans;
    deque<int>dq;
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            dq.push_back(i);
        }
    }
    if(dq.size()>0){
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    for(int i=k;i<n;i++){
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        if(arr[i]<0){
            dq.push_back(i);
        }
        if(dq.size()>0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

int main(){
    
    vector<int>arr={-8,2,3,-6,10};
    vector<int>ans=negativeNums(arr,2);
    for(auto i:ans)cout<<i<<" ";
    
    return 0;
}