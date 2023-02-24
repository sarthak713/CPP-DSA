#include<iostream>
#include<vector>
using namespace std;

/*
Kadane's Algorithm
Maximum Suarray Sum
T.C. = O(n), S.C. = O(1)
*/

int maxSubarraySum(vector<int>arr){
    int maxSum=INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++) {
        sum+=arr[i];
        maxSum=max(maxSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}

int main(){
    
    return 0;
}