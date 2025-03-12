#include<iostream>
#include<list>
#include<iterator>
using namespace std;


int main(){
    list<int> ll;  // Created List using inbuilt List Library 

    ll.push_back(23);  
    ll.push_back(20);
    ll.push_front(30);
    ll.pop_front();

    list<int> :: iterator itr;  // special type of Iterator to iterate through STL Containers

    for(itr = ll.begin() ; itr!= ll.end();itr++){
        cout<<(*itr)<<" ";
    }
}

