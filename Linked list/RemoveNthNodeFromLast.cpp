#include<iostream>
using namespace std;

class Node{

public:
   Node* next;
   int data;

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
// Calculate the size of Linled-List Or Number of Nodes present in Linked List
int size(){
    int Size = 0;
    Node* temp = Head;

    while(temp != NULL){
        Size++;
        temp = temp->next;
    }

    return Size;
}

void removeNthNode(int n){
    Node* prev = Head;

    for(int i = 1; i<(size()-n);i++){
        prev = prev->next;
    }

    prev->next = prev->next->next;
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

    ll.push_front(32);
    ll.push_front(2);
    ll.push_front(42);
    ll.push_front(3);
    ll.push_front(65);
    ll.printList();
    ll.removeNthNode(3);
    ll.printList();

}