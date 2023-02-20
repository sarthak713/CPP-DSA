#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

/*
Pairs 

- Given array containing N integers, number S denoting target sum
- Find 2 integers that pair up to form target sum. Only one pair exists

Brute Force:
    - form all pairs using 2 for loops
    - T.C. = O(n^2)
Approach 1:
    - sort array O(Nlog n)
    - use binary Search O(log n)
    - T.C. = O(Nlog n)
Approach 2:
    - iterate through arr O(N)
    - for each arr element, check for pair inside Unordered_Set
    - searching takes O(1) time
    - Add elements as you go along
    - T.C. = O(N)
*/

vector<int>pairSum(vector<int>arr,int sum){
    unordered_set<int>s;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        int x=sum-arr[i];               // pair element with arr[i] 
        if(s.find(x)!=s.end()){         // search set till end
            ans.push_back(x);           // if found, push pair elemend & arr[i] into answer vector
            ans.push_back(arr[i]);
            return ans;                 // return ans
        }
        s.insert(arr[i]);               // insert arr[i] into set
    }
    return {};
}

int main(){
    
    vector<int> arr={10,5,2,3,-6,9,11};
    int sum=47;
    vector<int>ans=pairSum(arr,sum);
    if(ans.size()==0)
        cout<<"No pair exists"<<endl;
    else
        cout<<ans[0]<<" "<<ans[1]<<endl;
    
    return 0;
}