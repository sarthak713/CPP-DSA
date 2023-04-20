#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
Combination Sum 2 (Leetcode 40)
*/

void solve(int index,int sum,vector<int>arr,vector<vector<int>>&ans,vector<int>output,int target){
    if(sum>=target){
        if(sum==target){
            ans.push_back(output);
        }
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        output.push_back(arr[i]);
        solve(i+1,sum+arr[i],arr,ans,output,target);
        output.pop_back();  
    }
}
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>output;
    solve(0,0,arr,ans,output,target);
    return ans;
}

int main(){
    
    vector<int>arr={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>>ans=combinationSum2(arr,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}