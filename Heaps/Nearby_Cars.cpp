#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car{

public:
    int inx;
    int dist;

    Car(int inx, int dist){
        this->inx = inx;
        this->dist = dist;
    }


    bool operator < (const Car &obj) const{
        return this->dist > obj.dist;
    }
};


void nearbyCars(vector<pair<int,int>> pos,int k){
    vector<Car> cars;

    for(int i = 0;i<pos.size(); i++){
        int distInx = pos[i].first * pos[i].first + pos[i].second * pos[i].second;
        cars.push_back(Car(i,distInx));
    }

    priority_queue<Car> pq(cars.begin(),cars.end());

    for(int i = 0; i<k; i++){
        cout<<"car"<<pq.top().inx<<"\n";
        pq.pop();
    }




}

int main(){

    vector<pair<int,int>> pos;


    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    nearbyCars(pos,2);

}