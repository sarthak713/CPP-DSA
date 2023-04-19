#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Print all Subsequences:
- contiguous or non contiguous sequences
- which follow order
*/

void solve(string s,vector<string>&ans,int i,string output){
    if(i>=s.size()){
        ans.push_back(output);
        return;
    }
    solve(s,ans,i+1,output);
    solve(s,ans,i+1,output+s[i]);
}
vector<string> subsequences(string s){
    vector<string>ans;
    solve(s,ans,0,"");
    return ans;
}

void solve(vector<int>arr,vector<vector<int>>&ans,vector<int>output,int i){
    if(i>=arr.size()){
        ans.push_back(output);
        return;
    }
    solve(arr,ans,output,i+1);
    output.push_back(arr[i]);
    solve(arr,ans,output,i+1);
    output.pop_back();
}
vector<vector<int>>subsequences(vector<int>arr){
    vector<vector<int>>ans;
    vector<int>output;
    solve(arr,ans,output,0);
    return ans;
}

int main(){
    
    string s="abc";
    vector<string>ans=subsequences(s);
    sort(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<endl;
    cout<<endl;

    vector<int>arr={1,2,3};
    vector<vector<int>>newArr=subsequences(arr);
    for(auto i:newArr){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}