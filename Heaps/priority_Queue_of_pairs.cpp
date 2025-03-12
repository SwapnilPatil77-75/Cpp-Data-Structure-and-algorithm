#include<iostream>
#include<queue>
#include<vector>
using namespace std;



struct comparePair{
    bool operator() (pair<string,int> &p1, pair<string,int> &p2){
        return p1.second < p2.second;
    }  // custome comparator struct to sort valaues on second parameter and 
};  // to create min-heap of pairs 
int main(){
    priority_queue<pair<string,int>, vector<pair<string,int>>,comparePair>pq;

    pq.push(make_pair("Swapnil",60));  // deafult the max heap will be created by 
    pq.push(make_pair("Aaliya",90)); // their first property 
    

    while(!(pq.empty())){
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}