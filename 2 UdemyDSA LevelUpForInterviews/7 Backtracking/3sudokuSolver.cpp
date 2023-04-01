#include<iostream>
#include<vector>
using namespace std;

/*
Sudoku Solver

- Sudoku solution must satisfy all conditions:
    - each of the digits 1-9 must occur exactly once in each row
    - each of the digits 1-9 must occur exactly once in each column
    - each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of grid 

T.C. = O(9^m)
S.C. = O(1)
*/

bool isSafe(int row,int col,int value,vector<vector<int> >&board){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==value){
            return false;
        }
        if(board[i][col]==value){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int> >&board){
    int n=board.size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int i=1;i<=9;i++){
                    if(isSafe(row,col,i,board)){
                        board[row][col]=i;
                        bool isPossible=solve(board);
                        if(isPossible){
                            return true;
                        }
                        else{
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int> >&sudoku){
    solve(sudoku);
}

int main(){

    vector<vector<int> >sudoku={
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    solve(sudoku);
    for(auto i:sudoku){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}