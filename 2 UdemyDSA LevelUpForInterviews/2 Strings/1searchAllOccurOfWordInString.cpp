#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> stringSearch(string big,string small){
    vector<int> result = {};
    int position=big.find(small);
    while(position!=-1){
        result.push_back(position);
        position=big.find(small,position+1);
    }
    return result;
}

int main(){

    string bigString = "I the movie, in movie great";
    string smallString = "movie";
    vector<int>ans=stringSearch(bigString, smallString);
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;
        
    return 0;
}