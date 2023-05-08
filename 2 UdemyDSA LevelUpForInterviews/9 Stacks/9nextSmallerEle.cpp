#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>nextSmaller(vector<int>arr){
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        while(s.top()>=arr[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    
    vector<int>arr={2,1,4,3};
    vector<int>ans=nextSmaller(arr);
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;
    
    return 0;
}