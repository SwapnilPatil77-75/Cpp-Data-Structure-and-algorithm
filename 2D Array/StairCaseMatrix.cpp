#include<iostream>
using namespace std;


bool search(int mat[4][4], int n, int m, int key){
    int i = n-1, j = 0;

    while(i<n && j>=0){
        if(mat[i][j] == key){
            cout<<"key found at "<< i<<","<<j<<" ";
            return true;
        }
        else if(key > mat[i][j]){
            j++;
        }
        else if(mat[i][j] > key){
            i--;
        }
    }
    cout<<"Key is not found "<<endl;
}


int main(){
    int arr[4][4] = {{10,20,30,40},
                     {15,25,35,45},
                     {27,29,37,48},
                     {32,33,39,50}};

cout<<search(arr,4,4,10)<<endl;
}