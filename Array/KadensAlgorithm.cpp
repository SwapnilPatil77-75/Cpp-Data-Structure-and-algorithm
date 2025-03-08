#include<iostream>
using namespace std;

void subarrays(int arr[], int n){
int MaxSum = INT32_MIN;
int currSum = 0;
for(int i =0; i<n; i++){
    currSum  += arr[i];
    MaxSum = max(currSum , MaxSum);
    if(currSum < 0){
        currSum = 0;
    }
}
cout<<MaxSum<<endl;
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr) / sizeof(int);

    subarrays(arr,n);
}