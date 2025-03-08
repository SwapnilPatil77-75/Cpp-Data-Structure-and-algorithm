#include<iostream>
using namespace std;

int linearSer(int arr[], int n, int key){
for(int i = 0; i<n ; i++){
  if(arr[i] == key){
    return i;
  }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,90,10};
    int n = sizeof(arr) / sizeof(int);
    int key ;
    cout<<"Enter the key to search ";
    cin>>key;
    cout<<linearSer(arr, n,key)<<endl;
}