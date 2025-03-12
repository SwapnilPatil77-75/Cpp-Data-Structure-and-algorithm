#include<iostream>
#include<unordered_map>
using namespace std;


void majorityElement(int arr[],int n){

    unordered_map<int,int> m;  // arr[i] = count;

    for(int i = 0; i<n; i++){
        
        
        if(m.count(arr[i])){
            m[arr[i]]++;
        }else{
            m[arr[i]] = 1;
        }
    }

    int target = n/3;

   for(pair<int,int>p :m){
    if(p.second > target){
        cout<<p.first<<","<<p.second<<endl;
    }
   }
   cout<<endl;
   return;
}

int main(){

    int arr[]={1,3,2,5,1,3,1,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<"\n";
    majorityElement(arr,9);



}