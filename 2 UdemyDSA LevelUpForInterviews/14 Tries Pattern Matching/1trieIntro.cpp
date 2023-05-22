#include<iostream>
using namespace std;

/*
Trie

Insertion:
    - search character
    - if found -> go forward
    - if not -> create node & go forward
Searching:
    - go to each character of string
    - in end, check if node is terminal or not
    - if yes -> string present
    - else -> string absent

Node* Structure of Trie:
    - for each node
        - char type data (char data)
        - can have 26 children (node* children[26])
        - terminal node to know where each string ends (bool isTerminal)
*/

class TrieNode{
public:
    char data;
    TrieNode*children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

int main(){
    
    
    
    return 0;
}