#include<iostream>
#include<vector>
using namespace std;

// https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

int foundIndex(vector<int>arr,int key){

}

int main(){
    
    vector<int>arr1={5, 6, 7, 8, 9, 10, 1, 2, 3};
    int k1=3;   // 8
    vector<int>arr2={5, 6, 7, 8, 9, 10, 1, 2, 3};
    int k2=30;  // -1
    vector<int>arr3={30, 40, 50, 10, 20};
    int k3=10;  // 3

    cout<<foundIndex(arr1,k1)<<endl;    
    cout<<foundIndex(arr2,k2)<<endl;    
    cout<<foundIndex(arr3,k3)<<endl;    
    
    return 0;
}