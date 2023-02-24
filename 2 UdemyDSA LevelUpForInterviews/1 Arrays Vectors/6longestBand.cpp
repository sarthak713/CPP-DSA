#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
Longest Band

- Given array with N integers, find longest band length
- Band = subsequence which can be reordered in a way that all elements appear consecutive
- Longest band is band that has maximum integers

Brute Force:
    - Sort array and find length of all bands
    - T.C. = O(nlog n)
Approach 1: 
    - iterate array, for each element
    - check if it is starting of a band or not
    - do similar for this element 
    - once we know the start, we ca generate the entire band
    - We need to look up elements: Most optimal way is unordered_set O(1)-search
        - As we iterate, if an element cannot be starting of band, we ignore that element
        - if it is then we search for consecutive elements in set
        - Now, if no more elements can be found, we store length of band
    - T.C. = O(n)
*/

int longestBand(vector<int>v){
    int n=v.size();
    int ans=0;
    unordered_set<int>set;
    for(int i:v){
        set.insert(i);
    }
    for(auto element:set){
        int count=0;
        int parent=element-1;
        if(set.find(parent)!=set.end()){
            continue;
        }
        else{
            while(set.find(element)!=set.end()){
                count++;
                element++;
            }
            ans=max(ans,count);
        }
    }
    return ans;
}

int main(){

    vector<int>v={1,9,3,0,18,5,2,4,10,12,6};  // ans=8
    cout<<longestBand(v)<<endl;


    
    return 0;
}