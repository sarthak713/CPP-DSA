#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Palindrome Partitioning (Leetcode 131)

- Given a string s
- Partition s such that every substring partition is a palindrome
- Return all possible palindrome partitioning of s

Input: s="aab"
Output: [["a","a","b"],["aa","b"]]

Input: s="aabb"
Output:[["a","a","b","b"],
        ["a,"a","bb"],
        ["aa","b","b"],
        ["aa","bb"]]

Brute Force:
    - for "aabb"
    - do partition where possible
        a|abb, aa|bb
    - now repeat for the second part of partition
        a|a|bb
        a|a|b|b
    - return when end is reached
*/

bool isPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void solve(int index,string s,vector<string>&output,vector<vector<string>>&ans){
    if(index>=s.size()){
        ans.push_back(output);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            output.push_back(s.substr(index,i-index+1));
            solve(index+1,s,output,ans);
            output.pop_back();
        }
    }
}

vector<vector<string>>partition(string s){
    vector<vector<string>>ans;
    vector<string>output;
    solve(0,s,output,ans);
    return ans;
}

int main(){
    
    string s="aabb";
    vector<vector<string>>ans=partition(s);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }

    return 0;
}