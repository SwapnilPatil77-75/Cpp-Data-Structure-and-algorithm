#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int connectNropes(vector<int> rope){
    // create a Min Heap 
    priority_queue<int ,vector<int>,greater<int>> pq(rope.begin(),rope.end());

    int cost = 0;

    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost = cost + min1+min2;
        pq.push(min1+min2);

    }

    cout<<"cost = "<<cost<<endl;
    return cost;

}

int main(){
    vector<int> ropes={4,3,2,6};

    connectNropes(ropes);
}