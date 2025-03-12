#include<iostream>
#include<queue>
using namespace std;




void printQ(queue<int> Q){
    while(!(Q.empty())){
        cout<<Q.front()<<" ";
        Q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    queue<int> Q;
int arr[5];
for(int i = 0;i<5; i++){
    cin>>arr[i];
}
for(int i = 0; i<5;i++){
    Q.push(arr[i]);
}


    // q.push(23);
    // q.push(30);
    // q.push(89);
    // printQ(q);
    // cout<<q.front()<<endl;

    // q.pop();
    // cout<<q.front()<<endl;
    printQ(Q);
    
}