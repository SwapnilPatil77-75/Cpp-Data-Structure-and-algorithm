#include<iostream>
using namespace std;

// Node Classs for 
class Node{
public:
   Node* next;  // Node Class Pointer 
   int data;

   Node(int val){   // Node class Constructor 
        data = val;
        next = NULL;
    }
};
class List{    // List Class 
    Node* Head;  // It's Implement the all the linked list functions 
    Node* Tail;

public:
  List(){
    Head = NULL;
    Tail = NULL;
  }

// To Add a Node to LinkList Front
void push_front(int val){
    Node* newNode = new Node(val);

    if(Tail == NULL){
        Head = Tail = newNode;
    }
    else{
        newNode->next = Head;
        Head = newNode;

    }

}
// To add a Node at Last of Linked-List
void push_back(int val){
    Node* newNode = new Node(val);
    
    if(Tail == NULL){   // If the Linked-List is empty Head and Tail will Point to 
        Head = Tail = newNode;  // first Node
    }else{
        Tail-> next = newNode;  // Tail next will connect to new Node
        Tail = newNode;         // NewNode will point To Tail i.e last node
    }
}

void pop_front(){
    Node* temp = Head;
    Head = Head->next;
    temp->next = NULL;
    delete temp;

}

void pop_back(){
    Node* temp = Head;
    while(temp->next->next != NULL){
        temp = temp->next;

    }

    temp->next = NULL;
    delete Tail;
    Tail = temp;
}


void printList(){
    Node* temp = Head;
    while(temp!=NULL){  // Find the Last node By trevesering through the entire Linked List 
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
bool isPresent(int val){
    Node* temp = Head;
    int idx = 0;
    while(temp != NULL){
        if(temp->data == val){
            return idx;
        }else{
        idx++;
        temp = temp->next;
    }
    }

    return -1;
}
};




int main(){

List ll;

ll.push_front(23);
ll.push_front(25);
ll.push_front(62);
ll.printList();
ll.push_back(20);
ll.printList();

ll.pop_front();
ll.printList();
ll.push_front(66);
ll.printList();
ll.pop_back();
ll.printList();
cout<<ll.isPresent(0);


return 0;
}