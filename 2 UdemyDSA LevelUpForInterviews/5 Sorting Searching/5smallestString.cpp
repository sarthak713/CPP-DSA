#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string x,string y){
    return x+y<y+x;
}

int main(){
    
    string arr[]={"c","cb","cba"};
    sort(arr,arr+3,compare);
    for(auto i:arr){
        cout<<i<<endl;
    }
    
    return 0;
}