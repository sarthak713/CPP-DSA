#include<iostream>
using namespace std;

/*
Check Subsets
- Given 2 strings
- function that determines whether 2nd string is subsequence of 1st

Input: condingminutes cines
Output: yes
*/

bool isSubset(string s1,string s2){
    int i=s1.length()-1;
    int j=s2.length()-1;
    while(i>=0 && j>=0){
        if(s2[j]==s1[i]){
            i--;
            j--;
        }else{
            i--;
        }
    }
    if(j==-1){
        return true;
    }
    return false;
}

int main(){
    
    string s="codingminutes";
    string t="lol";
    cout<<isSubset(s,t);
    
    return 0;
}