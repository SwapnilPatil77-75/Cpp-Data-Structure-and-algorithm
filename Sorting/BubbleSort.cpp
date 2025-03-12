#include<iostream>
using namespace std;


void printArr(int arr[] , int n);
void Bubblesort(int *arr, int n){

    for(int i = 0; i<n-1; i++){
        bool isSwap = false;
        for(int j = 0; j < n-i-1; j++){
         if(arr[j] < arr[j+1]){
            swap(arr[j], arr[j+1]);
            isSwap = true;
         }
        }
        if(!isSwap){
            return;
        }
    }
    printArr(arr, n);
}

void printArr(int arr[],int n){
    for(int i  = 0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 26,56,89,23,20};
    int n = sizeof(arr)/ sizeof(int);

    Bubblesort(arr,n);
}