#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Printing Subsequences with Sum K
*/

void solve(vector<int>arr,int k,vector<vector<int>>&ans,vector<int>&output,int index){
    if(index>=arr.size()){
        if(k==0){
            ans.push_back(output);
        }
        return;
    }
    solve(arr,k,ans,output,index+1);
    output.push_back(arr[index]);
    solve(arr,k-arr[index],ans,output,index+1);
    output.pop_back();
}

vector<vector<int>>subseqSumK(vector<int>&arr,int k){
    vector<vector<int>>ans;
    vector<int>output;
    solve(arr,k,ans,output,0);
    return ans;
}

int main(){
    
    vector<int>arr={1,2,1};
    vector<vector<int>>ans=subseqSumK(arr,2);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}