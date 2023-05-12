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

/* 
Vertical Traversal

- map horizontal distance, add nodes level wise:
    map < int , map < int , vector <int> > >
       horizontal    level     list of nodes
        distance
- To traverse level order wise, we need queue
    queue < pair < node* , pair < int , int > > >
                             horizontal , level
                              distance     
*/

vector<int>verticalOrder(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int, map<int, vector<int> > >nodes;
    queue<pair<node*, pair<int,int> > >q;
    q.push({root,{0,0}});                   // for root, level=0 & horizontal distance=0
    while(!q.empty()){
        pair<node*,pair<int,int> >front=q.front();  // front of queue
        q.pop();
        node*frontNode=front.first;                 // node
        int hd=front.second.first;                  // horizontal distance
        int level=front.second.second;              // level
        nodes[hd][level].push_back(frontNode->data);// put entry
        if(frontNode->left){
            q.push({frontNode->left,{hd-1,level+1}});
        }
        if(frontNode->right){
            q.push({frontNode->right,{hd+1,level+1}});
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    
    
    
    return 0;
}