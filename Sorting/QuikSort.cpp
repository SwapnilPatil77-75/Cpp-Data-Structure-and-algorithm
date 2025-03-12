#include<iostream>
using namespace std;

/// Time Complexity = O(log n)
// Worst Time Complexity = O(n^2)

int partision(int arr[],int si, int ei){
    int i = si-1;
    int pivot = arr[ei];
    cout<<i<<endl;

    for(int j = si; j<ei; j++){   
        if(arr[j]<= pivot){        // " > " sign for sorting array in descending order
            i++;                   // " < " sign for sorting array in ascending order
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);
    return i;
}
void QuickSort(int arr[], int si , int ei){
    if(si>=ei){
        return;
    }

    int pivot = partision(arr,si,ei);
    QuickSort(arr,si,pivot-1);
    QuickSort(arr,pivot+1,ei);
}
void printArr(int arr[]){
    for(int i  = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){

    int arr[] = {6,3,7,5,2,4};
    QuickSort(arr,0,5);
    printArr(arr);

}