#include<iostream>
#include<vector>
using namespace std;

/*
Mountain

- Write function which takes array input of diff integers
- Return length of highest mountain
- Mountain = adjacent ints that are strictly increasing until they reach a peak, then become strictly decreasing
- At least 3 numbers are required to form a mountain 

Trick:
    - iterate over array
    - identify peaks (previous < element > next)
    - check how big peak is:
    - move back - check how many elements are strictly decreasing
    - move forward - check how many elements are strictly decreasing
    - maintain biggest peak size
    - T.C. = O(N)
*/

int mountain(vector<int>arr, int n){
    int biggest=0;
    for(int i=1;i<n-1;){
        // check if current element is peak
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
            int count=1;
            // count backward
            int j=i;
            while(j>0 && arr[j-1]<arr[j]){
                count++;
                j--;
            }
            // count forward
            while(i<n-1 && arr[i]>arr[i+1]){
                count++;
                i++;
            }
            biggest=max(biggest,count);
        }
        else{
            i++;
        }
    }
    return biggest;
}

int main(){
    
    vector<int>arr={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int n=16;
    // output = 9
    cout<<mountain(arr,n)<<endl;
    
    
    return 0;
}