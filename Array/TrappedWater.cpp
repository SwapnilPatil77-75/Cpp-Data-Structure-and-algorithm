#include<iostream>
using namespace std;

void trapWat(int arr[] , int n){
    int leftMax[n] , rightMax[n];
    leftMax[0] = arr[0];
    rightMax[n-1] = arr[n-1];
    
    for(int i = 1; i<n; i++){
        leftMax[i] = max(leftMax[i-1],arr[i-1]);
        
    }
    
    for(int i = n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1],arr[i+1]);
        
    }
    int waterTrap = 0;
    for(int i =0; i<n; i++){
    int currwat = min(leftMax[i], rightMax[i]) - arr[i];
    if(currwat > 0){
        waterTrap += currwat;
    }
    else{
        currwat = 0;
    }
    }
    cout<<"Trapped water "<<waterTrap<<endl;
}

int main(){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int n  = sizeof(height) / sizeof(int);

    trapWat(height, n);
}