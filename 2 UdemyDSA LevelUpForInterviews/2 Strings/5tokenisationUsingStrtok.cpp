#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
String Tokenization (using strtok)
- strtok works on char arrays
*/

int main(){
    
    char input[1000];
    cin.getline(input,1000);
    char *token=strtok(input," ");
    while(token!=NULL){
        cout<<token<<endl;
        token=strtok(NULL," ");
    }
    
    return 0;
}