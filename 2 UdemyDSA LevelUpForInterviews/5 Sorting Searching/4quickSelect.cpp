#include<iostream>
#include<vector>
using namespace std;

/*
Quick Select
- take arr inoput
- return kth smallest element in arr

Input: arr={10,5,2,0,7,6,4} k=4
Output: 5
*/
int partition(vector<int>&arr,int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    } 
    int pivotIndex=s+count;
    swap(arr[s],arr[pivotIndex]);
    int i=s, j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

int quickSelect(vector<int>arr,int s,int e,int k){
    int p=partition(arr,s,e);
    if(p==k){
        return arr[p];
    }
    else if(k<p){
        return quickSelect(arr,s,p-1,k);
    }
    else{
        return quickSelect(arr,p+1,e,k);
    }
}

int main(){
    
    vector<int>arr={10,5,2,0,7,6,4};
    
    cout<<quickSelect(arr,0,6,1);
    
    return 0;
}