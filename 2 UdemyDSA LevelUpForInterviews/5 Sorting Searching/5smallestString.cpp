#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string x,string y){
    return x+y<y+x;
}

int main(){
    
    string arr[]={"c","cb","cba"};
    string arr1[]={"a","ab","aba"};
    sort(arr1,arr1+3,compare);
    for(auto i:arr1){
        cout<<i<<endl;
    }
    
    return 0;
}