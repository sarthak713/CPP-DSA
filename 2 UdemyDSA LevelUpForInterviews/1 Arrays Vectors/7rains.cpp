#include<iostream>
#include<vector>
using namespace std;

/*
Rains
- Given array representing elevation map
- width of each bar is 1
- compute total water it can trap

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Approach:
    - For a particular array element
    - Find highest bar on left, highest bar on right
    - but water will be restricted to lowest bar, on left or right
    - So we find minimum(highest left,highest right)
    - But we have height of current element also
    - so we subtract current element height from minimum(highest left,highest right)
    - min(highest(left),highest(right))-height[i]

Brute Force:
    - traverse array
    - for each element, go to its left & right to find maximum
    - then calculate
    - T.C. = O(n^2)
Optimized:
    - make 2 arrays, for left & right
        - for left array, traverse from start, store highest till current element
        - for right array, traverse from end, store highest till current element
    - traverse main array
        - for each element get highest of left & right from above arrays
        - find minimum & subtract current element
    - do this for all element & keep storing sum of water
    - T.C. = O(n), S.C. = O(n)
*/

int tappingRainwater(vector<int>arr){
    int n=arr.size();
    if(n<=2){
        return 0;
    }
    vector<int>left(n,0);
    vector<int>right(n,0);
    int water=0;
    left[0]=arr[0]; 
    for(int i=1;i<n;i++){
        left[i]=max(arr[i],left[i-1]);
    }
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(arr[i],right[i+1]);
    }
    for(int i=1;i<n-1;i++){
        int sum=min(left[i],right[i])-arr[i];
        water+=sum;
    }
    return water;
}

int main(){

    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2};
    cout<<tappingRainwater(arr)<<endl;
    
    return 0;
}