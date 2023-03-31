#include<iostream>
#include<vector>
using namespace std;

void solve(string s,string output,int index,vector<string>&ans){
    if(index>=s.size()){
        ans.push_back(output);
        return;
    }
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        solve(s,output+s[index],index+1,ans);
        swap(s[index],s[i]);
    }
}

vector<string>permutations(string s){
    vector<string>ans;
    solve(s,"",0,ans);
    return ans;
}

int main(){
    
    string s="ab";
    vector<string>ans=permutations(s);
    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}