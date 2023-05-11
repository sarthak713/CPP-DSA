#include<iostream>
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

// Zig Zag = left to right then right to left

vector<vector<int>>zigzag(node*root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<node*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            node*temp=q.front();
            q.pop();
            int index=flag?i:size-i-1;
            level[index]=temp->data;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        ans.push_back(level);
        flag=!flag;
    }
    return ans;
}

int main(){
    

    
    return 0;
}