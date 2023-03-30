#include<iostream>
#include<vector>
using namespace std;

/*
Generate Brackets
- Write function to generate all possible 
- n pairs of balanced parenthesis '(' and ')'

Input: 2
Output: ()(),(())

Input: 3
Output: ((())),(()()),()(()),(())(),()()()

For number n:
    - to make a valid parenthesis
    - we need to fill 2*n spaces
*/

void generateParenthesis(vector<string>&ans,string output,int n,int open,int close,int i){
    if(i==2*n){
        ans.push_back(output);
        return;
    }
    if(open<n){
        generateParenthesis(ans,output+'(',n,open+1,close,i+1);
    }
    if(close<open){
        generateParenthesis(ans,output+')',n,open,close+1,i+1);
    }
}

int main(){

    int n=3; 
    vector<string>ans;
    generateParenthesis(ans,"",n,0,0,0);
    for(auto i:ans){
        cout<<i<<endl;
    }    
    
    return 0;
}