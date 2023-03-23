#include<iostream>
#include<vector>
using namespace std;

/*
Rotated Search
- Search array which is rotated about a pivot point
- find index of given element

Approach 1:
    - find pivot
    - binary search 
Approach 2:
    - there are 2 monotonic lines / | /
    - key can lie on line 1 or line 2
    - we find mid
        - if mid is on line 1: then a[start]<=a[mid]
            - if a[start]<=key<=a[mid], then search left
            - else, search right
        - if mid is on line 2: then a[end]>=a[mid]
            - if a[mid]<=key<=arr[end], search right
            - else, search left
*/

int searchRotated(vector<int>arr,int key){
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[start]<=arr[mid]){
            if(arr[start]<=key && key<=arr[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        else{
            if(arr[mid]<=key && key<=arr[end]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    
    vector<int>arr={4,5,6,7,0,1,2,3};
    cout<<searchRotated(arr,10)<<endl;
    
    return 0;
}