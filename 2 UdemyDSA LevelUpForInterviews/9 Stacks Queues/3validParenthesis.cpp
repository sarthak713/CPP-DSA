#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top=st.top();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(){
    
    string s1="[()]{}{[()()]()}";
    string s2="())";
    cout<<isValid(s1)<<endl;
    cout<<isValid(s2)<<endl;

    return 0;
}