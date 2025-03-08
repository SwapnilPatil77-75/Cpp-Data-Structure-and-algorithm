#include<iostream>
using namespace std;

int  binarySer(int *arr, int n, int key){
    int st = 0, end = n-1;

    while(st <= end){
        int mid = (st+end)/2;

        if(key == arr[mid]){
            return mid + 1;
        }
        else if(key < arr[mid]){
            end = mid - 1;
        }
        else if(key > arr[mid]){
            st = mid + 1;
        }
      
    }
    return -1;
}

int main(){
    int arr[] = { 2,6,8,9,10,11,12,13};  // Sorted array 
    int n = sizeof(arr) / sizeof(int);
    int key ;
    cout<<"Enter the key to search ";
    cin>>key;
    cout<<binarySer(arr, n , key)<<endl;
}