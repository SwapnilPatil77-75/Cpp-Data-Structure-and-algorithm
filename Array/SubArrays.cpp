#include<iostream>
using namespace std;

void subarrays(int arr[], int n){

    for(int st = 0; st < n; st++){
        int currSum =0;
        for(int end = st ; end < n; end++){
        cout<<"{ ";
            for(int i = st; i <= end; i++){
              cout<<arr[i]<<" ";
            }
        cout<<"}"; 
        }
        cout<<endl;
    }
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr) / sizeof(int);

    subarrays(arr,n);
}