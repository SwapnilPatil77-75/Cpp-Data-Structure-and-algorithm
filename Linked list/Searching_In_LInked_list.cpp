#include<iostream>
using namespace std;


class Node{

public:
int data;
Node* next;

Node(int val){
    data = val;
    next = NULL;
}
};


class List{


Node* Head;
Node* Tail;
public:
List(){
    Head = NULL;
    Tail = NULL;
}

void push_back(int val){
    Node* newNode = new Node(val);

    if(Tail == NULL){
        Head = Tail = newNode;
    }else{
        Tail->next = newNode;
        Tail = newNode;
    }
}

bool isPresent(int val){
    Node* temp = Head;

    while(temp!=NULL){
        if(temp->data == val){
            cout<<temp->data<<" ";
            return 1;
        }
        temp = temp->next;
    }

    return -1;
}

void printList(){
    Node* temp = Head;
    while(temp != NULL){
     cout<<temp->data<<"->";
     temp = temp->next;
    }
    cout<<"NULL\n";
}
};


int main(){

    List ll;

    ll.push_back(20);
    ll.push_back(50);
    ll.push_back(99);
    ll.push_back(1);
    ll.push_back(71);
    ll.printList();
    ll.isPresent(19);
}

