#include<iostream>
using namespace std;

/*
Flip Bits


*/

int flipBits(int*arr,int n){
    int maxCount=0;
    int count=0;
    int defaultOnes=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1)
        defaultOnes++;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count--;
        }
        else{
            arr[i]=1;
            count++;
        }
        maxCount=max(maxCount,count);
        if(count<0){
            count=0;
        }
    }
    return maxCount+defaultOnes;
}

int main(){

    int n=7;
    int arr[]={1,0,1,0,0,0,0};
    cout<<flipBits(arr,n)<<endl;

    return 0;
}