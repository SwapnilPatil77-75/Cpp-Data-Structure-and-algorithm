#include<iostream>
using namespace std;

int gridWays(int i ,int j, int m, int n){
    if(i == n-1 && j == m-1){
        return 1;
    }

    if(i >= n|| j >= m){
        return 0;
    }

    int val1 = gridWays(i,j+1, n,m);
    int val2 = gridWays(i+1,j,m,n);
    return val1+val2;
}


int main(){
cout<<gridWays(0,0,3,3);


    return 0;
}