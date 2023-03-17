#include<iostream>
using namespace std;

/*
String Window
- Given 2 strings, one big one small
- find 'smallest window' in big that contains all chars of small
- window can have additional chars than required
- if small as duplicates, then those duplicates must be present with same or higher count in window

Input: s1="hello_world", s2="lol"
Output: llo

Sliding Window Approach (Expand & Contract)
    - build frequency hashmap for small
    - in big, iterate from left to right
    - put chars inside window, maintain hashmap of window with frequencies
    - check if window pattern lies inside window as we put more chars in window
- For big:"hello"
    small:"oel"
    output:"ello"
- Hashmap for small = [o:1,e:1,l:1]
- Iterate big & insert inside Hashmap for big 
- Check if window has all chars that are in small Hashmap
    - [h:1]                 all chars not present 
    - [h:1,e:1]             all chars not present
    - [h:1,e:1,l:1]         all chars not present 
    - [h:1,e:1,l:2]         all chars not present, 'o' is missing
    - [h:1,e:1,l:2,o:1]     Now this Hashmap has all chars that are in Small Hashmap
- We store these chars in window 'hello'
- Now to find smallest window, remove unecessary chars not in small Hashmap
- contract from left
    - [h:0,e:1,l:2,o:1]     all chars still present in small
- If we remove further, window will be invalid
- If more chars we present we would expand further
*/

string stringWindow(string s,string p){
    // frequency arrays for pattern & window
    int pattrnFreq[256]={0};
    int windowFreq[256]={0};
    // determine chars in pattern for small string
    for(int i=0;i<p.length();i++){
        pattrnFreq[p[i]]++;
    }
    int count=0;    // for chars matched in both frequency arrays
    int start=0;    // to contract window when all chars are found
    int minWindow=INT_MAX;
    int startIndex=-1;  // start for best window
    int windowSize;
    for(int i=0;i<s.length();i++){
    // EXPAND
        // expand window by including current character
        windowFreq[s[i]]++;
        // if currChar is in Pattern FreqArr &&
        // freq of currChar in Window is less or equal to freq of currChar in Pattern FreqArr
        if(pattrnFreq[s[i]]!=0 && windowFreq[s[i]]<=pattrnFreq[s[i]]){
            count++;
        }
    // CONTRACT
        // if all pattern chars are present in current Window
        // then start contracting from left to remove unwanted chars
        // if s[start] is not in Pattern && freq of s[start] is > patternFreq[s[start]]
        if(count==p.length()){
            while(pattrnFreq[s[start]]==0 || windowFreq[s[start]]>pattrnFreq[s[start]]){
                windowFreq[s[start]]--;
                start++;
            }
            // update window size with minimum window size
            windowSize=i-start+1;
            if(windowSize<minWindow){
                minWindow=windowSize;
                startIndex=start;
            }
        }
    }
    if(startIndex==-1){
        return "No window found";
    }
    return s.substr(startIndex,minWindow);
}

int main(){
    
    string s1="hello_world";
    string s2="lol";            // llo
    
    string s3="fizzbuzz";
    string s4="fuzz";           // fizzbu

    string s5="helloe";
    string s6="eol";            // loe

    cout<<stringWindow(s1,s2)<<endl;
    cout<<stringWindow(s3,s4)<<endl;
    cout<<stringWindow(s5,s6)<<endl;
    
    return 0;
}