#include<iostream>
using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
void SelectionSort(int *arr, int n){
    for(int i = 0; i<n-1; i++){
        int mininx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[mininx]){
                mininx = j;
            }
        }
        swap(arr[i], arr[mininx]);
    }
    printArr(arr , n);
}

int main(){
    int arr[] = {20,16,42,30,56,80,20,45,60};
    int n = sizeof(arr) / sizeof(int);

    SelectionSort(arr,n);
}