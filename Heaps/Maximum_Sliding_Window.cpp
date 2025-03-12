#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void maximumSlidingWindow(vector<int> arr, int k){

    priority_queue<pair<int,int>> pq;

    for(int i = 0; i<k;i++){
        pq.push(make_pair(arr[i],i));
    }

    cout<<"max is "<<pq.top().first<<endl;

    for(int i = k; i<arr.size();i++){
        while(!(pq.empty()) && pq.top().second < (i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr[i],i));
        cout<<"max is "<<pq.top().first<<endl;
    }

    return;
}

int main(){

    vector<int> arr ={1,3,-1,-1,5,3,6,7};

    maximumSlidingWindow(arr,3);

}