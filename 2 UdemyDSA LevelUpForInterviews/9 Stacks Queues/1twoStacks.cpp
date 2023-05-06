#include<iostream>
using namespace std;

class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;
public:
    TwoStack(int n){            // Initialize TwoStack
        size=n;
        arr=new int[size];
        top1=-1;
        top2=n;
    }
    void push1(int data){       // Push in stack 1
        if(top1==size-1 || top1==top2-1){
            return;
        }
        top1++;
        arr[top1]=data;
    }
    void push2(int data){       // Push in stack 2
        if(top2==0 || top2==top1+1){
            return;
        }
        top2--;
        arr[top2]=data;
    }
    int pop1(){                 // Pop from stack 1 & return popped element
        if(top1==-1){
            return -1;
        }
        int ele=arr[top1];
        top1--;
        return ele;
    }
    int pop2(){                 // Pop from stack 2 & return popped element
        if(top2==size){
            return -1;
        }
        int ele=arr[top2];
        top2++;
        return ele;
    }
};


int main(){
    
    

    return 0;
}