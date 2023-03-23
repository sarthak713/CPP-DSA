#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Frequncy Count
- Given a sorted arr containing repeated elements
- Find frequency of given element K
*/
int firstIndex(vector<int>arr,int key){
    int l=0;
    int r=arr.size();
    int left=-1;
    int mid=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==key){
            left=mid;
            r=mid-1;
        }
        else if(arr[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return left;
}
int lastIndex(vector<int>arr,int key){
    int l=0;
    int r=arr.size();
    int right=-1;
    int mid=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==key){
            right=mid;
            l=mid+1;
        }
        else if(arr[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return right;
}
int frequencyCount(vector<int>arr,int key){
    int l=firstIndex(arr,key);
    int r=lastIndex(arr,key);
    return r-l+1;
}

int main(){
     
    vector<int>arr={0,1,1,1,1,2,2,2,3,4,4,5,10};
    cout<<frequencyCount(arr,2)<<endl;
    cout<<upper_bound(arr.begin(),arr.end(),2)-lower_bound(arr.begin(),arr.end(),2)<<endl;
    
    return 0;
}