#include<iostream>
using namespace std;


void sum(int arr[3][3], int n, int m){
    int Sum = 0;
    for(int j = 0; j<m; j++){
        Sum += arr[1][j];
    }

    cout<<" The sum of second row is "<<Sum<<endl;
}

int main(){
    int arr[3][3] = {{1,4,9},{11,4,3},{2,2,3}};
    sum(arr, 3,3);
}

