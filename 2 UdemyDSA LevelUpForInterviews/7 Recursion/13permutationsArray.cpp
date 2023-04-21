#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>arr,vector<vector<int>>&ans,int index){
    if(index>=arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i!=index && arr[i]==arr[index])continue;
        swap(arr[i],arr[index]);
        solve(arr,ans,index+1);
        swap(arr[i],arr[index]);
    }
}

vector<vector<int>>permutations(vector<int>&arr){
    vector<vector<int>>ans;
    solve(arr,ans,0);
    return ans;
} 
 
int main(){
    
    vector<int>arr={1,2};
    vector<vector<int>>ans=permutations(arr);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<' ';
        }cout<<endl;
    }
    
    return 0;
}