#include<iostream>
#include<vector>
using namespace std;

/*
Housing
- Along one side of road there is sequence of vacant plots of land.
- Each plot has a diff area (non-zero)
- So areas form a sequence A[1],A[2]...A[N]
- you want to buy K acres of land to build a house
- Find all segments of contiguous plots (subsection in sequence)
- whose sum is equal to K

Input: Plots = {1,3,2,1,4,1,3,2,1,1,2}, K = 8
Output: {2,5} {4,6} {5,9}
*/

vector<vector<int> > subarrSumEqualK(vector<int>arr,int k){
    int n=arr.size();
    vector<vector<int> >ans;
    int sum=0;
    int i=0,j=0;
    while(j<n){
        sum+=arr[j];
        j++;
        while(sum>k && i<j){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            ans.push_back({i,j-1});
        }
    }
    return ans;
}

int main(){
    
    vector<int>arr={1,3,2,1,4,1,3,2,1,1};
    int k=8;
    vector<vector<int> >ans=subarrSumEqualK(arr,k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    
    
    return 0;
}