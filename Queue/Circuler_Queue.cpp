#include<iostream>
using namespace std;


class Queue{

int* arr;
int capacity;
int currSize;

int f ,r;

public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = 0;
        r = -1;
    }
    void push(int data){
        if(currSize == capacity){
            cout<<"Queue is full\n";
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop(){
         if(empty()){
            cout<<"Queue is EMPTY\n";
            return;
        }
        f = (f + 1) % capacity;
        currSize--;
       
    }

    int front(){
        if(empty()){
            cout<<"Queue is Empty";
            return -1;
        }
        //f = (f+1) % capacity;
        return arr[f];    
    }

    bool empty(){
       return currSize == 0;
    }



};


int main(){

    Queue q(4);
    q.push(23);
    q.push(56);
    q.push(50);
    q.push(66);

    q.pop();
    q.push(73);
   cout<< q.front()<<endl;
}