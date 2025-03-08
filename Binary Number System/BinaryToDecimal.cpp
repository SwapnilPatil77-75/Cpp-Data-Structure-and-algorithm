#include<iostream>
using namespace std;

void biTodeci(int num){
int n = num;
int pow = 1;
int decimal = 0;
    while(n != 0){
    int rem = n % 10;
    decimal =  decimal + rem * pow ;
    pow *= 2 ;
    n = n/10;
    }
cout<<decimal<<endl;
}

int main(){
    biTodeci(10101);
}