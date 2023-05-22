#include<iostream>
using namespace std;

// Trie Searching & Insertion

class Trie {

public:

    /** Initialize your data structure here. */

    bool isLeaf;
    Trie*children[26];

    Trie() {
        this->isLeaf=false;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }

    /** Inserts a word into the trie. */

    void insertUtil(Trie*root,string word){
        if(word.size()==0){
            root->isLeaf=true;
            return;
        }
        int index=word[0]-'a';              // get index of first char of word, assume word is CAPITAL
        Trie*child;                         // Initialize node to insert
        if(root->children[index]!=NULL){    // Present
            child=root->children[index];        // move forward
        }
        else{                               // Absent
            child=new Trie();                   // make node value as 1st char
            root->children[index]=child;        // make children[index] not NULL & put in value
        }
        insertUtil(child, word.substr(1));  // recursive call from next char 
    }
    void insert(string word) {
        Trie*root=this;
        insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */

    bool searchUtil(Trie*root,string word){
        if(word.size()==0){
            return root->isLeaf;
        }
        int index=word[0]-'a';
        Trie*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        Trie*root=this;
        return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */

    bool startUtil(Trie*root,string word){
        if(word.size()==0){
            return true;
        }
        int index=word[0]-'a';
        Trie*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return startUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        Trie*root=this;
        return startUtil(root,prefix);
    }
    
};

int main(){
    
    Trie *t=new Trie();
    t->insert("abcd");
    cout<<t->search("abcd")<<endl;
    
    return 0;
}