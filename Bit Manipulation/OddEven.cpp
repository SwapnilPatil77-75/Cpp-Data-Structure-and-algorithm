#include<iostream>
using namespace std;


void oddEven(int n){
    if(n & 1 == 1){
        cout<<"Odd NUmber ";
    }
    else{
        cout<<"Even number "<<endl;
    }
}

bool isPowerof2(int n){

    if(!(n & n-1) ){
        return true;
    }
    else{
        return false;
    }
}
void updateBit(int n, int i, int val){
    //int mask = ~(1<<i);  // used to clear or set the bit 
    n = n & ~(1<<i);    // clear the bit first 
    
    n = n | (val<<i);  // set the bit if the val is one or keep as it is if bit is 0s
    cout<<n<<endl;
    
    
}
int main(){

// oddEven(5);
// oddEven(50);
// cout<< (64 & 63)<<endl;
//cout<<isPowerof2(64)<<endl;

updateBit(7,1,0);
}