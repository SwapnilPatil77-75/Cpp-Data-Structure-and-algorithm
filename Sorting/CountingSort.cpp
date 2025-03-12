#include<iostream>
using namespace std;

void printArr(int arr[] , int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void CountingSort(int *arr , int n){
    int freq[10000] = {0};
    int minval = INT32_MAX;
    int maxval = INT32_MIN;

    for(int i = 0; i<n; i++){   // Find the minvalue and maxval in array 
        minval = min(arr[i] , minval);
        maxval = max(arr[i] , maxval);
    }

    for(int i =0; i<n; i++){
        freq[arr[i]]++;      // update the freq array as per the freq of the element
    }                        // appear in the array 

    for(int i = minval , j = 0; i<maxval; i++){
        while(freq[i] > 0){
            arr[j++] = i;  // write the freq val until corresponf to the i index
            freq[i]--; // 
        }
    }
    printArr(arr,n);
}

int main(){
    int arr[] = { 1,2,1,3,3,4,5,4,7};
    int n = sizeof(arr) /  sizeof(int);
    CountingSort(arr,n); 
}