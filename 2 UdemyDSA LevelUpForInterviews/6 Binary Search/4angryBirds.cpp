#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Angry Birds

- there is a long wire along straight line (length N), containing bird nests
- there are B birds, that become angry with each other, once in a nest
- to stop birds form hunting each other, assign birds to nests 
- such that minimum distance between any two birds is maximum
- Return largest minimum distance

Time Complexity of code below: O(n log n)
*/

bool isPossible(vector<int>arr,int birds,int mid){
    int bird=1;
    int last=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=mid){
            bird++;
            if(bird==birds){
                return true;
            }
            last=arr[i];
        }
    }
    return false;
}

int main(){
    
    vector<int>arr{1,2,4,8,9};
    int birds=3;
    int n=arr.size();
    
    sort(arr.begin(),arr.end());
    
    int l=0;
    int r=arr[n-1]-arr[0];
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(isPossible(arr,birds,mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}