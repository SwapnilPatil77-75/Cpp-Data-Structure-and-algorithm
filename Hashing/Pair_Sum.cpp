#include<iostream>
#include<unordered_map>
using namespace std;


void pairSum(int arr[],int target){
    unordered_map<int,int> m;
    for(int i = 0; i<7;i++){
        int l = arr[i];
        int comp = target - arr[i]; // complimet is the required nnumber
                                    // after adding the current number and 
        if(m.count(comp)){
            cout<<m[comp]<<","<<i<<endl;
            return;
        }else{
            m[arr[i]] = i;
        }
    }
}

int main(){

    int arr[] ={1,2,7,11,15,9,6};
    pairSum(arr,16);
}