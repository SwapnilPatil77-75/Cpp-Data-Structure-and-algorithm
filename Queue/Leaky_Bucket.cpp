#include<iostream>
#include<queue>
using namespace std;


int main(){
    int arr[10];
    queue<int> packetQ;
    int i=0;
    cout<<"Enter the continues packets with space in between them "<<endl;
    while(i != 10){
        cin>>arr[i];
        i++;
    }
    
    for(int j = 0; j<10;j++){
        packetQ.push(arr[j]);
    }
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    while(!(packetQ.empty())){
        cout<<"processed packet "<<packetQ.front()<<endl;
        packetQ.pop();
    }
}