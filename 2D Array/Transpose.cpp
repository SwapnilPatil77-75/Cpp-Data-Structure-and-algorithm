#include<iostream>
using namespace std;


void Transpose(int arr[4][3], int n, int m){
    int transpose[m][n] = {{0}};

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
     
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            transpose[j][i] = arr[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[4][3] = {{1,2,3}
                     ,{4,5,6}
                     ,{7,8,9}
                     ,{10,11,12}};

    Transpose(arr,4,3);
}