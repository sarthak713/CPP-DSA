#include<iostream>
#include<vector>
using namespace std;

/*
Subsets of Array
*/

void findSubsets(vector<int>arr,int index,vector<int>output,vector<vector<int> >&ans){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    findSubsets(arr,index+1,output,ans);
    output.push_back(arr[index]);
    findSubsets(arr,index+1,output,ans);
    return;
}

vector<vector<int> >subsets(vector<int>& arr){
    vector<vector<int> >ans;
    vector<int>output;
    findSubsets(arr,0,output,ans);
    return ans;
}

int main(){
    
    vector<int>arr={1,2,2};

    vector<vector<int> >ans=subsets(arr);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<' ';
        }cout<<endl;
    }

    return 0;
}