#include<iostream>
#include<stack>
using namespace std;

// Minimum Cost to Make String Valid

int findMinCost(string s){
    int n=s.size();
    if(n%2!=0){
        return -1;
    }
    stack<char>st;
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch=='{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    int open=0,clos=0;
    while(!st.empty()){
        if(st.top()=='{'){
            open++;
        }
        else{
            clos++;
        }
        st.pop();
    }
    int ans=(open+1)/2 + (clos+1)/2;  
    return ans;
}

int main(){
    
    string s1="{{}}";
    string s2="}{}}{{}{";
    cout<<findMinCost(s1)<<endl;
    cout<<findMinCost(s2)<<endl;
    
    return 0;
}