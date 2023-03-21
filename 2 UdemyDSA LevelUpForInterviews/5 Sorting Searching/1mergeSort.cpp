#include<iostream>
#include<vector>
using namespace std;

/*
Merge Sort
- Divide array in 2 parts
- Recursively sort left & right parts
- Merge left and right subarrays (using merge sorted arrays algo)

Recursion works in Depth First Manner
*/

void merge(vector<int>&arr,int s,int e){
    int mid=s+(e-s)/2;
    int i=s;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(arr[j]);
        j++;
    }
    int a=0;
    for(int i=s;i<=e;i++){
        arr[i]=temp[a];
        a++;
    }
    cout<<"Printing Arr: ";
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return;
}

void mergeSort(vector<int>&arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    cout<<"Firs: ";
            for(int i=s;i<=mid;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
    mergeSort(arr,s,mid);
    cout<<"Seco: ";
            for(int i=mid+1;i<=e;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
    mergeSort(arr,mid+1,e);
    return merge(arr,s,e);
}

int main(){
    
    vector<int>arr={10,5,2,0,7,6,4};
    mergeSort(arr,0,arr.size()-1);
    cout<<endl;
    for(auto i:arr)cout<<i<<" ";
    cout<<endl;
    
    return 0;
}