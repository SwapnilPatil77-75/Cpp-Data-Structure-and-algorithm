#include<iostream>
using namespace std;

void printArr(int *arr, int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[8] = {2,6,8,1,3,6,4,7};

    sort(arr, arr+8);  // here array is 
    printArr(arr,8);
}