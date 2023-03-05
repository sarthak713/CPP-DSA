#include<iostream>
#include<cstring>
using namespace std;

/*
Space 20

- Given string
- write func to replace spaces in string with '%20'
- Given that string has sufficient space at end to hold more chars

Input: "hello world, how are you?"
Output: "hello%20world,%20how%20are%20you?"

*/

void spaceTwenty(char *s){
    int spaces=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' ')
            spaces++;
    }
    int index=strlen(s)+2*spaces;
    s[index]='\0';
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]==' '){
            s[index-1]='0';
            s[index-2]='2';
            s[index-3]='%';
            index-=3;
        }
        else{
            s[index-1]=s[i];
            index--;
        }
    }
}

int main(){
    
    char input[1000];
    cin.getline(input,1000);
    spaceTwenty(input);
    cout<<input<<endl;

    return 0;
}