#include<iostream>
#include<vector>
using namespace std;

long long maxSubSumKConcat(vector<int>&arr,int n,int k){
	vector<int>newArr;
    for(int i=0;i<k;i++){
        for(int j=0;j<arr.size();j++){
            newArr.push_back(arr[j]);
        }
    }
    int maxSum=0;
    int sum=0;
    for(int i=0;i<newArr.size();i++){
        sum+=newArr[i];
        maxSum=max(maxSum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}

int main(){
    
    int n=2;
    int k=3;
    vector<int>arr={1,3};
    cout<<maxSubSumKConcat(arr,n,k)<<endl;
    
    
    return 0;
}