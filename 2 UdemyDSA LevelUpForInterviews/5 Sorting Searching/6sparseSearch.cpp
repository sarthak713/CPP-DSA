#include<iostream>
#include<vector>
using namespace std;

/*
Sparse Search
- Apply Binary search
- take 3 pointers: left,mid,right
- if we get empty at mid
    - update mid to nearest non-empty string
    - by traversing linearly in both directions
*/

int sparse(vector<string>arr,string str){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        int mid=(s+e)/2;
        int left=mid-1;
        int right=mid+1;
        if(arr[mid]==""){
            while(1){
                if(left<s && right>e){
                    return -1;
                }
                else if(right<=e && arr[right]!=""){
                    mid=right;
                    break;
                }
                else if(left>=s && arr[left]!=""){
                    mid=left;
                    break;
                }
                left--;
                right++;
            }
        }
        else if(arr[mid]==str){
            return mid;
        }
        else if(arr[mid]<str){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

int main(){
    
    vector<string>arr={"ai","","","bat","","","car","cat","","","dog",""};
    string s="bat";
    cout<<sparse(arr,s)<<endl;
    
    return 0;
}