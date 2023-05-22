#include<iostream>
#include<vector>
using namespace std;

/*
Longest Common Prefix

Input: {"coding","coder","codingninja"}
Output: "cod"

- Insert Words in trie
- traverse string until childCount is 1
- And add chars in string
- return when childCount!=1
*/

class Trie{
public:
    int childCount;
    bool isTerminal;
    Trie*children[128];
    Trie(){
        this->childCount=0;
        this->isTerminal=false;
        for(int i=0;i<128;i++){
            this->children[i]=NULL;
        }
    }
    void insert(string word){
        Trie*root=this;
        for(int i=0;i<word.size();i++){
            if(root->children[word[i]]==NULL){
                root->childCount++;
                root->children[word[i]]=new Trie();
            }
            root=root->children[word[i]];
        }
        root->isTerminal=true;
    }
};

string longComPref(vector<string>arr){
    string ans="";
    Trie *t=new Trie();
    for(auto i:arr){
        t->insert(i);
    }
    string s=arr[0];
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(t->childCount==1){
            ans.push_back(ch);
            t=t->children[ch];
        }
        else{
            break;
        }
        if(t->isTerminal){
            break;
        }
    }
    return ans;
}

int main(){
    
    vector<string>arr={"coing","coder","codingninja"};
    string ans=longComPref(arr);
    cout<<ans<<endl;
    
    return 0;
}