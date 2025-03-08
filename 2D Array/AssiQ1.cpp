#include<iostream>
using namespace std;
// to check how many times 7 presentin an array
void timeOf7(int arr[][3], int n, int m){
    int times = 0;  // 

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 7){
                times++;
            }
        }
    }
    cout<<"NO of times 7 present is "<<times<<endl;
}

int main(){
    int arr[2][3] = {{4,7,8},{8,8,7}};

    timeOf7(arr,2,3);
}