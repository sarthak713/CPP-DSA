#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

/*
Sort Strings
- Given list of strings: s1,s2,...sn-1
- each has digits and spaces
- number of spaces is same for each entry
- implement a variation of sort command
- no strings contain consecutive spaces
- no string starts or ends with space
- spaces are used to divide strings into columns, 
  which can be used as key in comparisons

Input:            Output:
3                 82 12
92 022            77 13
82 12             92 022
77 13
2 false numeric

Explaination: The key for ordering is 2, reversal is false &
ordering is numeric. Therefore, keys 022,12,13 should be ordered
as 12,13,022. Final Output is = 82 12, 77 13, 92 022.
*/

string extractStringAtKey(string str,int key){
    char*s=strtok((char*)str.c_str()," ");
    while(key>1){
        s=strtok(NULL," ");
        key--;
    }
    return (string)s;
}

bool numericCompare(pair<string,string>s1,pair<string,string>s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return stoi(key1)<stoi(key2);
}
bool lexicoCompare(pair<string,string>s1,pair<string,string>s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return key1<key2;
}

int main(){
    
    int n;
    cin>>n;
    cin.get();  // consume extra \n
    string temp;
    vector<string>v;
    for(int i=0;i<n;i++){
        getline(cin,temp);          // takes entire string as a line
        v.push_back(temp);
    }
    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;   // takes individual strings as input

    // Extract keys for comparison
    vector<pair<string,string> >vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i],extractStringAtKey(v[i],key)});
    }
    // sort
    if(ordering=="numeric"){
        sort(vp.begin(),vp.end(),numericCompare);
    }else{
        sort(vp.begin(),vp.end(),lexicoCompare);
    }
    if(reversal=="true"){
        reverse(vp.begin(),vp.end());
    }
    for(int i=0;i<n;i++){
        cout<<vp[i].first<<endl;
    }


    return 0;
}