#include<iostream>
#include<cstring>
using namespace std;

/*
LeetCode 1910 - Remove All occurences of Subtring

- Given 2 strings
- find leftmost occurence of substring & remove from main string
- do this until all occurences are removed

Input = "daabcbaabcbc", "abc"
Output = "dab"
*/

string removeOccurrences(string s, string part) {
    int l1=s.length();
    int l2=part.length();
    int index=s.find(part);
    while(index!=-1){
        s.erase(index,l2);
        index=s.find(part);
    }
    return s;
}

int main(){
    
    string s1="axxxxyyyyb";
    string s2="xy";
    cout<<removeOccurrences(s1,s2)<<endl;
    
    
    return 0;
}