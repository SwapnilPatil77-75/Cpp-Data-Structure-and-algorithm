#include<iostream>
using namespace std;

void rangeBitClear(int num , int i , int j){
    cout<<(~0)<<endl;
    int a = (~0) << (j+1);   // Clear the bits to j range 
    cout<<a<<endl;
    int b = (1 << i) - 1;    // set the left bits upto I(th) Bit  
    cout<<b<<endl;

    int mask = a |  b;       // OR the bits and range of bits will cleard
    cout<<mask<<endl;

    num = num & mask;        // the bits will clear 
    cout<<num<<endl; 
}

int main(){
    rangeBitClear(15,1,3);
}