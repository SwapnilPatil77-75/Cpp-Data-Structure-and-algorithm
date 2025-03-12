#include<iostream>
using namespace std;



int partision(int arr,int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for(int j = si; j<ei; j++){
        if(arr[j]<= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);
}
int mergeSort(int arr, int si , int ei){
    if(si>=ei){
        return;
    }

    int pivot = partision(arr,si,ei);
    mergeSort(arr,si,pivot-1);
    mergeSort(arr,pivot+1,ei);
}

int main(){

    int arr[] = {6,3,7,5,2,4};


}