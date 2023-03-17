#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

/*
Sorted Subsequences
- Given a string
- print all subsequencs of string
- sorted by length & lexographic (if length is same)

Input: abcd
Output: a,b,c,d,ab,ac,ad,bc,bd,cd,abc,acd,bcd,abcd
    - We have subsequences of length 1,2,3,4

Approach:
- Recursion & then sorting
- for each char, it will either be in the substring or not
- traverse string and make recursive call
*/

void sortedSubseq(string s,string output, vector<string>&v){
    if(s.size()==0){
        v.push_back(output);
        return;
    }
    sortedSubseq(s.substr(1), output+s[0], v);
    sortedSubseq(s.substr(1), output, v);
}

bool compare(string s1, string s2){
    if(s1.length()==s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main(){
    
    string s="abc";
    vector<string>v;
    sortedSubseq(s,"",v);
    sort(v.begin(),v.end(),compare);
    for(auto i:v){
        cout<<i<<endl;
    }
    
    return 0;
}