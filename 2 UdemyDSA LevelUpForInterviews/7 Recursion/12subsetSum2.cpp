#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
Subsets 2 (Leetcode 90)
*/

void solve(int index,vector<int>arr,vector<vector<int>>&ans,vector<int>output){
    ans.push_back(output);
    for(int i=index;i<arr.size();i++){
        if(i!=index && arr[i]==arr[i-1]){
            continue;
        }
        output.push_back(arr[i]);
        solve(i+1,arr,ans,output);
        output.pop_back();
    }
}

vector<vector<int>>subsets(vector<int>arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>output;
    solve(0,arr,ans,output); 
    return ans;
}

int main(){
    
    vector<int>arr={1,2,2};
    vector<vector<int>>ans=subsets(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" "; 
        }cout<<endl;
    }

    return 0;
}