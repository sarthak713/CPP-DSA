#include<iostream>
#include<vector>
using namespace std;

/*
Backtracking:
    - check each possible way
    - then return the best path

Rat In A Maze:
    - print all possible paths from src(0,0) to dest(n-1,n-1)
    - Rat can move up, down, left, right
Approach:
    - take visited array, all 0 initially
    - We have to print sorted paths, 
      so if we check paths in Lexicographical order only, 
      then no need to sort answer vector in end
    - Check D->L->R->U
    - To go to new position, we check if:
        - it is valid, 1 is present in matrix array
        - not already visited, 0 in visited array
        - it lies inside matrix, 0<=position<n
        
T.C. = O(4^(n*n))
S.C. = O(n*m)
*/

bool isSafe(int newX,int newY,int n,
            vector<vector<bool> >&visited,
            vector<vector<int> >&arr)
{
    if(newX>=0 && newX<n && newY>=0 && newY<n && visited[newX][newY]==0 && arr[newX][newY]==1){
        return true;
    }
    return false;
}

void solve(int x,int y,int n,
           vector<vector<int> >&arr,
           vector<string>&ans,
           vector<vector<bool> >&visited,
           string path)
{
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    if(isSafe(x+1,y,n,visited,arr)){    // DOWN
        solve(x+1,y,n,arr,ans,visited,path+'D');
    }
    if(isSafe(x,y-1,n,visited,arr)){    // LEFT
        solve(x,y-1,n,arr,ans,visited,path+'L');
    }
    if(isSafe(x,y+1,n,visited,arr)){    // RIGHT
        solve(x,y+1,n,arr,ans,visited,path+'R');
    }
    if(isSafe(x-1,y,n,visited,arr)){    // UP
        solve(x-1,y,n,arr,ans,visited,path+'U');
    }
    visited[x][y]=0;
}

vector<string>searchMatrix(vector<vector<int> >&arr,int n){
    vector<string>ans;
    vector<vector<bool> >visited(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,n,arr,ans,visited,path);
    return ans;
}

int main(){
    
    vector<vector<int> >arr={
        {1,0,0,0},
        {1,1,0,0},  // DDRDRR
        {1,1,0,0},  // DRDDRR
        {0,1,1,1}
    };

    vector<string>ans=searchMatrix(arr,4);
    for(auto i:ans){
        cout<<i<<endl;
    }
    
    return 0;
}