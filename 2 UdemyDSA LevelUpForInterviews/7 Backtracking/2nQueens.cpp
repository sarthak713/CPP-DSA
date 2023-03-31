#include<iostream>
#include<vector>
using namespace std;

/*
N-Queens (Leetcode 51)
    - Place N queens in a matrix, such that
    - each row has a queen
    - each column has a queen
    - no two queens attack each other

For a 4x4 Matrix:
    0 0 1 0
    1 0 0 0
    0 0 0 1
    0 1 0 0

Approach:
    - Go column by column, try placing queen at each row
    - and call for the next column at each row, such that queens do not attack
    - when we backtrack, we remove queens that were placed before
    - we just write code to solve for 1st column each row & call function recursively for next columns

T.C. = O(N!)
S.C. = O(N*N)

- Can optimize isSafe function, using HashMap (searching is O(1))
*/

bool isSafe(int row,int col,int n,vector<vector<int> >&board){
    int x=row;
    int y=col;
    while(y>=0){    // check horizontal, to the left
        if(board[x][y]==1){
            return false;
        }
        y--;
    }
    x=row;
    y=col;
    while(x>=0 && y>=0){    // check upper left diagonal
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=row;
    y=col;
    while(x<n && y>=0){     // check lower left diagonal
        if(board[x][y]==1){
            return false;
        }
        x++; 
        y--;
    }
    return true;
}

void solve(int col,int n,vector<vector<int> >&board,vector<vector<int> >&ans){
    if(col==n){
        vector<int>temp;
        for(auto i:board){
            for(auto j:i){
                temp.push_back(j);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,n,board)){
            board[row][col]=1;
            solve(col+1,n,board,ans);
            board[row][col]=0;
        }
    }
}

vector<vector<int> >solveNQueens(int n) {
    vector<vector<int> >board(n,vector<int>(n,0));
    vector<vector<int> >ans;
    solve(0,n,board,ans);
    return ans;
}

int main(){
    
    vector<vector<int> >ans=solveNQueens(4);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}