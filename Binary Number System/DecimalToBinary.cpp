#include<iostream>
using namespace std;

void deciToBi(int num){
    int n = num;
    int pow = 1;
    int bi = 0;
    while(n != 0){
        int rem = n % 2;
        bi += rem * pow ;
        pow *= 10;
        n = n/2;
    }
cout<<"Binary of No "<<num<<" is "<<bi<<endl;
}

int main(){
    deciToBi(3);
}