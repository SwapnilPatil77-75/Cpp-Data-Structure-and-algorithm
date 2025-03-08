#include<iostream>
using namespace std;

int main(){

    int max = 0;
    int arr[] = {5,70,6,3,90,50};
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i < n ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout<<"Maximum no is "<< max<<endl;
}