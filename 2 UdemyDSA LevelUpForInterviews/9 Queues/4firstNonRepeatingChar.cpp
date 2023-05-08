#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

string nonRepeatingChar(string s){
    unordered_map<char,int>count;
    queue<int>q;
    string ans="";
    for(int i=0;i<s.size();i++){
        count[s[i]]++;
        q.push(s[i]);
        while(!q.empty()){
            if(count[q.front()]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    
    string s="aabc";
    string output=nonRepeatingChar(s);   // "a#bb"
    cout<<output<<endl;

    return 0;
}