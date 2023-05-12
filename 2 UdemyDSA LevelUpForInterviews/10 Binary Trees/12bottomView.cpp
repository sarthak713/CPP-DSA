#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Bottom View

vector<int>bottomView(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>nodes;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        pair<node*,int>front=q.front();
        q.pop();
        node*frontNode=front.first;
        int hd=front.second;
        nodes[hd]=frontNode->data;
        if(frontNode->left){
            q.push({frontNode->left,hd-1});
        }
        if(frontNode->right){
            q.push({frontNode->right,hd+1});
        }
    }
    for(auto i:nodes){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    
    
    
    return 0;
}