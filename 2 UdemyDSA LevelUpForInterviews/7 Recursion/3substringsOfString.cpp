#include<iostream>
#include<vector>
using namespace std;

void solve(string s,int index,string output,vector<string>&arr){
    if(index>=s.length()){
        arr.push_back(output);
        return;
    }
    solve(s,index+1,output,arr);
    output.push_back(s[index]);
    solve(s,index+1,output,arr);
    return;
}

vector<string>substrings(string s){
    vector<string>ans;
    solve(s,0,"",ans);
    return ans;
}

int main(){
    
    string s="abc";
    vector<string>ans=substrings(s);
    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}