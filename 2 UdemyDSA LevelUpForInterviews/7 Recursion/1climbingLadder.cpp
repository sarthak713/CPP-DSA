#include<iostream>
using namespace std;

/*
Climbing Ladder
- given a ladder containing N steps
- you can take a jump of 1, 2 or 3 at each step
- Find number of ways to climb the ladder

Complexity:
- T.C. = Exponential 
    - Bad Time Complexity
    - Use Dynamic Programming to Optimize
    - DP eliminates suplicate calls
    - DP can only optimize Overlapping Subproblems
*/

int climbLadder(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return climbLadder(n-1)+climbLadder(n-2)+climbLadder(n-3);
}

int main(){
    
    int n=3;
    cout<<climbLadder(n)<<endl;

    return 0;
}