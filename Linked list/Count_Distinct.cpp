#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;


int countDist(vector<int> arr){

    unordered_set<int> s;

    for(int i = 0; i<arr.size(); i++){
        s.insert(arr[i]);
    }

    return s.size();
}


int main(){

    vector<int> arr ={1,2,3,4,5,4,4,9,8,1,6};

    cout<<countDist(arr);
}