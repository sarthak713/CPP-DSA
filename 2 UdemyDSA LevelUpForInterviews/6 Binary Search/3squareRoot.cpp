#include<iostream>
using namespace std;

/*
Square Root
- Given n & p
- find sqrt of n upto p decimal places
- without library function

Input: N=10,P=3
Output: 3.162

Approach:
- find the largest number, whose sqrt is <= n 
- using binary search, get the integer part of the answer (log n)
- for decimal places, use linear search (as decimal place num can be 0-9 only)
*/

float squareRoot(int n,int p){
    int s=0;
    int e=n;
    float ans=0;
    // binary search
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    // linear search
    float inc=0.1;
    for(int i=1;i<=p;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main(){
    
    int n=10;
    int p=4;
    cout<<squareRoot(n,p)<<endl;
    
    return 0;
}