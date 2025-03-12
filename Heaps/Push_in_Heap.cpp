#include<iostream>
#include<vector>
using namespace std;


void push(vector<int> &vec , int inx,int val){

vec.push_back(val);  // 1) insert the val 

// fix the heap 
int child = inx;
int parent = (inx-1)/2;

while(vec[child] > vec[parent]){
    swap(vec[child] ,vec[parent]);
    child = parent;
    parent = (child-1)/2;
}

}


int main(){

    vector<int> heap ={8,4,5,1,2};
    for(int i = 0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    push(heap,5,9);

    for(int i = 0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;


}
