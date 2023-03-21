#include<iostream>
using namespace std;

/*
Bit Manipulation Techniques

Bitwise Operators (operate on binary representation of data)

For Binary:
 5  4 3 2 1 0   Powers
32 16 8 4 2 1   Numbers

For a 32-bit integer: First Bit is MSB which is signed bit
If MSB = 1, then number is negative
The other 31-bits are magnitude/value of the number
To find Magniture of a Negative Number, we take 2s Complement (invert all bits, add 1)

- AND &&
- OR ||
- XOR ^                 : if both bits are same, result is 0
- NOT ~                 : flips all bits, including MSB
- Left Shift <<         : 
- Right Shift >>        : 

*/

int main(){
    
    int n=0;
    cout<<(!n)<<endl;
    
    return 0;
}