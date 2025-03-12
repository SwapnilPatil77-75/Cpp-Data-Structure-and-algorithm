#include<iostream>
using namespace std;



class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* Head;
    Node* Tail;


public:
    Queue(){
        Head = NULL;
        Tail = NULL;
    }


    void push(int val){
        Node* newNode = new Node(val);

        if(Tail == NULL){
            Head = Tail = newNode;
        }
        else{
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    void pop(){
        Node* temp = Head;
        Head = Head->next;
        delete temp;
    }

    int front(){
        return Head->data;
    }

    bool empty(){
        return Head == NULL;
    }

    void printQ(){
        Node* temp = Head;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};


int main(){
    Queue Q;

    Q.push(23);
    Q.push(24);
    Q.push(73);
    Q.printQ();
    cout<<Q.front()<<endl;
    Q.pop();
    cout<<Q.front()<<endl;
    Q.printQ();
}