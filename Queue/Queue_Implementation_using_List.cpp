#include<iostream>
#include<list>
#include<iterator>
using namespace std;

// template<class T>
// class Queue{
// public:
//     list<T> queue;

//     void push(T val){
//         queue.push_back(val);
//     }

//     void pop(){
//         queue.pop_front();
//     }

    // T Front(){
    //     return queue.front();
    // }

    // // void printQ(){
    // //     while(!(queue.empty())){
    // //         cout<<Front()<<" ";
    // //         pop();
    // //     }
    // // }

    // void printQ(list<T> Q){
    //     list<T>::iterator itr;

    //     for(itr = Q.begin(); itr != Q.end(); itr++){
    //         cout<<*itr<<" ";
    //     }
//     }


// };

void printQ(list<int> q){
    list<int>::iterator itr;
    for(itr = q.begin(); itr != q.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
}



int main(){

   
    list<int> Q;

    Q.push_back(26);
    Q.push_back(65);
    Q.push_back(30);
    Q.pop_front();
    printQ(Q);

}
