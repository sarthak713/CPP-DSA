#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int>nextSmaller(vector<int>arr,int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>prevSmaller(vector<int>arr,int n){
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=0;i<n;i++){
        while(s.top()!=-1 && arr[s.top()]>=arr[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int largestHistogramRectArea(vector<int>arr){
    int n=arr.size();
    vector<int>prev=prevSmaller(arr,n);
    vector<int>next=nextSmaller(arr,n);
    int maxAns=INT_MIN; 
    for(int i=0;i<n;i++){
        if(next[i]==-1){
            next[i]=n;
        }
        int area=arr[i]*(next[i]-prev[i]-1);
        maxAns=max(maxAns,area);
    } 
    return maxAns;
}

int maxArea(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    vector<int>first=arr[0];
    int area=largestHistogramRectArea(first);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                arr[i][j]=arr[i][j]+arr[i-1][j];
            }
            else{
                arr[i][j]=0;
            }
        }
        area=max(area,largestHistogramRectArea(arr[i]));
    }
    return area;
}

int main(){
    
    vector<vector<int>>arr= 
        {{0,1,1,0,0},
         {1,1,1,1,1},
         {1,1,1,1,1},
         {1,1,0,0,0}};
    vector<vector<int>>arr1= 
        {{1,1,1,1,1},
         {1,1,1,1,1},
         {1,1,1,1,1}};
    cout<<maxArea(arr)<<endl;
    cout<<maxArea(arr1)<<endl;

    return 0;
}