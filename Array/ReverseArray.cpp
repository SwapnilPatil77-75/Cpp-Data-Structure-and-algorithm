#include<iostream>
using namespace std;
// void reverse(int *arr , int n){
// for(int i = 0, j = n-1; i <= j ; i++ , j--){
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }

void reverse(int *arr, int n){
    int inx = 0;
    int end = n-1;

    while(inx<end){
        swap(arr[inx],arr[end]);
        inx++;
        end--;
    }

    


for(int i = 0; i<n; i++){
    cout<<arr[i]<<",";
}
cout<<endl;
}

int main(){
    int arr[] = { 2,5,7,6,8,9};
    int n = sizeof(arr) / sizeof(int);
    reverse(arr,n);
}