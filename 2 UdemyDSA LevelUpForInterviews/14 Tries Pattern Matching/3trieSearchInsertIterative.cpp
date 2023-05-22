#include<iostream>
using namespace std;

/*
Insertion Deletion Searching in TRIE 

Time Complexities of all Operations: O(length of word)
*/

class Trie {
public:
    
    bool isTerminal=false;
    Trie*children[128];

    Trie() {
        this->isTerminal=false;
        for(int i=0;i<128;i++){
            this->children[i]=NULL;
        } 
    }
    
    void insert(string word) {
        Trie*root=this;
        for(int i=0;i<word.size();i++){
            if(root->children[word[i]]==NULL){
                root->children[word[i]]=new Trie();
            }
            root=root->children[word[i]];
        }
        root->isTerminal=true;
    }
    
    bool search(string word) {
        Trie*root=this;
        if(root==NULL){
            return false;
        }
        for(int i=0;i<word.size();i++){
            root=root->children[word[i]];
            if(root==NULL){
                return false;
            }
        }
        return root->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Trie*root=this;
        if(root==NULL){
            return false;
        }
        for(int i=0;i<prefix.size();i++){
            root=root->children[prefix[i]];
            if(root==NULL){
                return false;
            }
        }
        return true;
    }

    void removeWord(string word){
        Trie*root=this;
        if(root==NULL){
            return;
        }
        for(int i=0;i<word.size();i++){
            root=root->children[word[i]];
            if(root==NULL){
                return;
            }
        }
        root->isTerminal=false;
    }
};

int main(){
    
    
    
    return 0;
}