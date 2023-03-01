#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Subarray Sort
- Given array of size at least 2
- find smallest subarray that needs to be sorted in place
- such that entire array becomes sorted
- if already sorted, return [-1,-1], else return start & end index of smallest subarray

Input: [1,2,3,4,5,8,6,7,9,10,11]
Output: [5,7]

Brute Force:
    - Make temp array & Sort it
    - compare values of both arrays from left and right & return indices
    - T.C. = O(n log n) 
Optimized:
    - Sorted array with always follow linear increasing path
    - But non-sorted array with not be increasing, & not ordered
    - find elements which are out of order
        - find element greater than next element a[i]>a[i+1]
        - find element smaller than previous element a[i]<a[i-1]
        - element which is Not a[i-1]<a[i]<a[i+1]
    - find smallest & largest element from out of order elements
    - find correct positions of these 2 elements
        - traverse array from start & end
        - find position where a[i-1]<element<a[i+1]
        - return correct indices of these 2 elements
    - T.C. = O(n) 

*/

// Brute Force
vector<int>subarrSort(vector<int>arr){
    int n=arr.size();
    vector<int>ans(2);
    int start=0;
    int end=n-1;
    vector<int>temp=arr;
    sort(arr.begin(),arr.end());
    while(arr[start]==temp[start] && start<n){
        start++;
    }
    while(arr[end]==temp[end] && end>=0){
        end--;
    }
    if(start==n){
        return {-1,-1};
    }
    ans[0]=start;
    ans[1]=end;
    return ans;
}

// Optimized
bool outOfOrder(vector<int>arr,int i){
    int x=arr[i];
    if(i==0){
        return x>arr[1];
    }
    if(i==arr.size()-1){
        return x<arr[i-1];
    }
    return x>arr[i+1] || x<arr[i-1];
}
vector<int>subarrSort2(vector<int>arr){
    int n=arr.size();
    if(n==1){
        return {-1,-1};
    }
    int small=INT_MAX;
    int great=INT_MIN;
    for(int i=0;i<n;i++){
        int x=arr[i];
        if(outOfOrder(arr,i)){
            small=min(small,x);
            great=max(great,x);
        }
    }
    if(small==INT_MAX){
        return {-1,-1};
    }
    int left=0;
    while(small>=arr[left]){
        left++;
    }
    int right=n-1;
    while(great<=arr[right]){
        right--;
    }
    return {left,right};
}

int main(){
    
    vector<int>arr={1};
    vector<int>ans=subarrSort2(arr);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    
    return 0;
}