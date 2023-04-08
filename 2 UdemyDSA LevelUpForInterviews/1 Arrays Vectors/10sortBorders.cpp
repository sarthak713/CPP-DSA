#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortBorders(vector<vector<int> >&v){
    int n=v.size();
    int m=v[0].size();
    int rowStart=0,rowEnd=n-1;
    int colStart=0,colEnd=m-1;
    while(rowStart<=rowEnd && colStart<=colEnd){
        vector<int>arr;
        for(int i=colStart;i<=colEnd;i++){
            arr.push_back(v[rowStart][i]);
        }
        rowStart++;
        for(int i=rowStart;i<=rowEnd;i++){
            arr.push_back(v[i][colEnd]);
        }
        colEnd--;
        for(int i=colEnd;i>=colStart;i--){
            arr.push_back(v[rowEnd][i]);
        }
        rowEnd--;
        for(int i=rowEnd;i>=rowStart;i--){
            arr.push_back(v[i][colStart]);
        }
        colStart++;
        
        sort(arr.begin(),arr.end());

        rowStart--;colEnd++;rowEnd++;colStart--;

        int j=0;
        for(int i=colStart;i<=colEnd;i++){
            v[rowStart][i]=arr[j];
            j++;
        }
        rowStart++;
        for(int i=rowStart;i<=rowEnd;i++){
            v[i][colEnd]=arr[j];
            j++;
        }
        colEnd--;
        for(int i=colEnd;i>=colStart;i--){
            v[rowEnd][i]=arr[j];
            j++;
        }
        rowEnd--;
        for(int i=rowEnd;i>=rowStart;i--){
            v[i][colStart]=arr[j];
            j++;
        }
        colStart++;
    }
}

int main(){
    
    vector<vector<int> >v={
        {1,3,2,4,1},
        {5,6,7,1,2},
        {9,8,2,3,1},
        {4,3,2,1,4},
        {4,3,2,1,4}
    };
    sortBorders(v);
    for(auto i:v){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    
    return 0;
}