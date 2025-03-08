#include<iostream>
using namespace std;


int SingleElement(int arr[],int n){
    int low , high;
    if(n == 1){         // check if has only single element 
        return arr[0];
    }
    if((arr[0] != arr[1])){
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]){
       return arr[n-1];
    }
        low = 1;
        high = n-2;
    
    while(low <= high){
       int mid = (low + high)/2;
       if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
        return arr[mid];
       } 

       if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1])){
        low = mid+1;
       }
       else{
        high = mid - 1;
       }
    }
    return -1;
}
int main(){
    int arr[] = {1,1,2,2,3};
    int n =  sizeof(arr) / sizeof(int);
    cout<<SingleElement(arr,n);
   
}