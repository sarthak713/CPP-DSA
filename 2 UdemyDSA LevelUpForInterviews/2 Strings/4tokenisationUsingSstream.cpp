#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;

/*
String Tokenization (using sstream)
- Tokenizing a string denotes splitting string with respect to some delimiter
- Input = "today is a sunny day"
- Output = "today","is","a","sunny","day"
*/

int main(){
    
    string s;
    getline(cin,s);
    stringstream buffer(s);     
    // initialize stringstream object with s
    // stringstream object supports left & right shipt operators which allows us to read & write data to stream
    string token;               
    vector<string>tokens;
    while(getline(buffer,token,' ')){
        tokens.push_back(token);
    }
    for(auto i:tokens){
        cout<<i<<",";
    }cout<<endl;
    
    return 0;
}