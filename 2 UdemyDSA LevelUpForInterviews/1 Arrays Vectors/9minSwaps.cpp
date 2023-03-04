#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Minimum Swaps
- Given array of size n
- find minimum number of swaps needed to make arr sorted

Input: {5,4,3,2,1}
Output: 2

Approach:
    - make vector of pairs <arr[i],i>
    - sort this new vector
    - iterate new vector
    - check if i==v[i].second
        - if correct continue
        - else, swap v[i] & v[v[i].second], i-- to check again & ans++
    T.C. = O(nlog n), S.C. = O(n)
*/

int minSwaps(vector<int>arr){
    int n = arr.size();
    int ans=0;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        v[i]={arr[i],i};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int element=v[i].second;
        if(i!=element){
            swap(v[i],v[element]);
            i--;
            ans++;
        }
        else{
            continue;
        }
    }
    return ans;
}

int main(){
    
    vector<int>arr={1,4,3,2,5};
    cout<<minSwaps(arr)<<endl;
    
    return 0;
}