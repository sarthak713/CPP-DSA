#include<iostream>
#include<vector>
using namespace std;

/*
Count Inversions
- Given arr, count total number of inversions
- Inversion 
    - Two elements a[i] a[j] form an inversion 
    - if a[i] > a[j] and i < j 

Input = {0,5,2,3,1}
Output = 5
*/

void merge(vector<int>&arr,int s,int e,int &count){
    int mid=s+(e-s)/2; 
    int i=s;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            count+=mid-i+1;
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }
    int a=0;
    for(int i=s;i<=e;i++){
        arr[i]=temp[a++];
    }
}

void countInversion(vector<int>&arr,int s,int e,int &count){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    countInversion(arr,s,mid,count);
    countInversion(arr,mid+1,e,count);
    return merge(arr,s,e,count);
}

int main(){
    
    vector<int>arr={2, 4, 1, 3, 5};
    int count=0;
    countInversion(arr,0,4,count);
    cout<<count<<endl;

    return 0;
}