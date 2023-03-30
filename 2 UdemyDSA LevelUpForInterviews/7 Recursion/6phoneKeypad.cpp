#include<iostream>
using namespace std;

/*
Phone Keypad:
- Given a number n, modern keypad
- find all possible strings
- generated using that number
*/

string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printKeypadOutput(string input,string output,int i){
    if(input[i]=='\0'){
        cout<<output<<endl;
        return;
    }
    int currDigit=input[i]-'0';
    if(currDigit==0 || currDigit==1){
        printKeypadOutput(input,output,i+1);
    }
    for(int j=0;j<keypad[currDigit].size();j++){
        printKeypadOutput(input,output+keypad[currDigit][j],i+1);
    }
}

int main(){
    
    string input="234";
    string output="";
    printKeypadOutput(input,output,0);
    
    return 0;
}