#include<iostream>
#include<stack>
using namespace std;

class Queue{
stack<int> s1;
stack<int> s2;

public:

    void Push(int val){
        while(!(s1.empty())){  // Move all Elements from s1 to s2 until s1 is empty 
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);
        while(!(s2.empty())){
            s1.push(s2.top());
            s2.pop();
        }

    }

    int front(){
        return s1.top();
    }

    void Pop(){
        s1.pop();
    }

};


int main(){
   Queue Q;
   Q.Push(23);
   Q.Push(26);
   Q.Push(28);
   cout<<Q.front()<<endl;
   Q.Pop();
   Q.Push(30);
   cout<<Q.front()<<endl;
   Q.Pop();
   Q.Pop();
   cout<<Q.front()<<endl;


}