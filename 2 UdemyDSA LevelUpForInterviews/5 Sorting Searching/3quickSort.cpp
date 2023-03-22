#include<iostream>
#include<vector>
using namespace std;

/*
Quick Sort
- pick element & put it in right place
    - such than elements to its left are Small
    - elements to its right are Greater
- This is partitioning
- Use recursion to sort

For Partitioning:
    - pick pivot
    - count elements < pivot
    - put pivot at position
    - Satisfy condition where: 
        - elements at left < arr[pivot]
        - elements at right > arr[pivot]
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

void quickSort(vector<int>&arr,int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1); 
    quickSort(arr,p+1,e);
}

int main(){
    
    vector<int>arr={10,5,2,0,7,11,6};
    quickSort(arr,0,6);
    for(auto i:arr){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}