#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://www.geeksforgeeks.org/chocolate-distribution-problem/

int findMinDiff(vector<int>arr,int m){
    sort(arr.begin(),arr.end());
    int minDiff=INT_MAX;
    for(int i=0;i<=arr.size()-m;i++){
        minDiff=min(minDiff,arr[i+m-1]-arr[i]);
    }
    return minDiff;
}

int main(){
    
    vector<int>arr1={7, 3, 2, 4, 9, 12, 56};
    int m1=3;   // 2
    vector<int>arr2={3, 4, 1, 9, 56, 7, 9, 12};
    int m2=5;   // 6
    vector<int>arr3={12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m3=7;   // 10

    cout<<findMinDiff(arr1,m1)<<endl;
    cout<<findMinDiff(arr2,m2)<<endl;
    cout<<findMinDiff(arr3,m3)<<endl;
    
    return 0;
}