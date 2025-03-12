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

void push_front(int val){
    Node* newNode = new Node(val);

    if(Tail == NULL){
        Head = Tail = newNode;
    }else{
        newNode->next = Head;
        Head = newNode;
    }
}
public:
    void reverse(){
    Node* prev = NULL;
    Node* curr = Head;
    Node* Next = Head->next;

    while(curr != NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    Head = prev;
}

void printList(){
    Node* temp = Head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL\n";
    reverse();
}
};

int main(){

    List ll;
    ll.push_front(20);
    ll.push_front(10);
    ll.push_front(65);
    ll.push_front(98);
    ll.push_front(65);

    // ll.printList();
    // ll.reverse();
    ll.printList();
}