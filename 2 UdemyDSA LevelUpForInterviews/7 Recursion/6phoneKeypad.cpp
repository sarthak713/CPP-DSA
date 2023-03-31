#include<iostream>
#include<vector>
using namespace std;

/*
Leetcode 17

Phone Keypad:
- Given a number n, modern keypad
- find all possible strings
- generated using that number
*/

string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void solve(string digits,string output,int index,vector<string>&ans){
    if(index>=digits.size()){
        ans.push_back(output);
        return;
    }
    int num=digits[index]-'0';
    string s=keypad[num];
    for(int i=0;i<s.size();i++){
        solve(digits,output+s[i],index+1,ans);
    } 
}

vector<string> letterCombinations(string digits){
    vector<string>ans;
    if(digits.size()==0){
        return ans;
    }
    solve(digits,"",0,ans); 
    return ans;
}

int main(){
    
    string digits="23";
    string output="";
    vector<string>ans=letterCombinations(digits);
    for(auto i:ans)
        cout<<i<<endl;
    
    return 0;
}