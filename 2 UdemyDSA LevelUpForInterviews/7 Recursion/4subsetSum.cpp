#include<iostream>
#include<vector>
using namespace std;

int countSubsets(vector<int> arr,int index,int sum){
    if(index>=arr.size()){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    int include=countSubsets(arr,index+1,sum-arr[index]);
    int exclude=countSubsets(arr,index+1,sum);
    return include+exclude;
}

int main(){
    
    vector<int>arr={1,2,3,4,5};
    int sum=6;
    cout<<countSubsets(arr,0,sum)<<endl;

    return 0;
}