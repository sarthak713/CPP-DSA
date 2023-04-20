#include<iostream>
#include<vector>
using namespace std;

/*
Combination Sum (Leetcode 39)

- Given array, & target integer
- return list of all unique combinations of candidates
- where chosen numbers sum to target
- Same number may be chosen an unlimited number of times
*/

void solve(int i,int sum,vector<int>arr,vector<vector<int>>&ans,vector<int>output,int target){
    if(sum>=target || i>=arr.size()){
        if(sum==target){
            ans.push_back(output);
        }
        return;
    }
    output.push_back(arr[i]);
    solve(i,sum+arr[i],arr,ans,output,target);
    output.pop_back();
    solve(i+1,sum,arr,ans,output,target);
}

vector<vector<int>>combinationSum(vector<int>&arr,int target){
    vector<vector<int>>ans;
    vector<int>output;
    solve(0,0,arr,ans,output,target);
    return ans;
}

int main(){
    
    vector<int>arr={2,3,5};
    int target=8;
    vector<vector<int>>ans=combinationSum(arr,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}