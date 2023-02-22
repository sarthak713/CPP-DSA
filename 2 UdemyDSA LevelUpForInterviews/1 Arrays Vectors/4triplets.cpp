#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
Triplets 

- Given array containing N integers, number S denoting target sum
- Find all distinct integers that add to form target sum. 
- Numbers & triples should be ascending order

Brute Force:
    - use 3 loops
    - T.C. = O(n^3)
Approach 1:
    - iterate array, take 1 element
    - use pair sum on other 2 elements
    - this uses unordered_set, increases S.C.
    - T.C. = O(n^2), S.C. = O(n)
Approach 2:
    - sort array O(nlog n)
    - iterate over array, take one element
    - use 2 pointer pairSum (start & end) to find other 2 elements
    - this takes, T.C. = O(n^2)
*/

vector<vector<int> >triplets(vector<int>arr,int sum){
    vector<vector<int> >ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<=arr.size()-3;i++){
        int element=sum-arr[i];
        int start=i+1;
        int end=arr.size()-1;
        while(start<end){
            int sumEle=arr[start]+arr[end];
            if(sumEle>element){
                end--;
            }
            else if(sumEle<element){
                start++;
            }
            else{
                ans.push_back({arr[i],arr[start],arr[end]});
                start++;
                end--;
            }
        }
    }
    return ans;
}

int main(){
    
    vector<int>arr={1,2,3,4,5,6,7,8,9,15};
    int s=18;
    auto result=triplets(arr,s);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }cout<<endl;
    }
    
    
    return 0;
}