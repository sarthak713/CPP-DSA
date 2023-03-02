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
    - know correct position of each element in arr
        - use sort function, O(nlog n)
    - For a cycle containing N to be swapped, we need (N-1) swaps
*/

int minSwaps(vector<int>arr){

    int ans=0;
    int n=arr.size();

    vector<pair<int,int> >v(n);
    for(int i=0;i<n;i++){
        v[i].first=arr[i];
        v[i].second=i;
    }

    sort(v.begin(),v.end());            // sort

    vector<bool>vis(n,false);           // Main Logic

    for(int i=0;i<n;i++){

        if(vis[i] || v[i].second==i){   // if element is visited OR element is in right prosition
            continue;
        }

        int cycle=0;                    // if visiting element for first time
        while(!vis[i]){                 // looking at old & new postions & completing cycle
            vis[i]=true;
            int next=v[i].second;
            i=next;
            cycle+=1;
        }
        ans+=(cycle-1);                 // for n elements, n-1 swaps required

    }

    return ans;

}

int main(){
    
    vector<int>arr={5,4,3,2,1};
    cout<<minSwaps(arr)<<endl;
    
    return 0;
}