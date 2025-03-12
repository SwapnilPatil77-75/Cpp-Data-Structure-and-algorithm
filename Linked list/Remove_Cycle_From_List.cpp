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

public:
    Node* Head;
    Node* Tail;

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


    void printList(){
        Node* temp = Head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }

        cout<<"NULL\n";
    }


   void removeCycle(Node* Head){
    Node* slow = Head;
    Node* fast = Head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            isCycle = true;
            break;
        }
    }

    if(!isCycle){
        return;
    }else{
        cout<<"Cycle Present"<<endl;
    }
    slow = Head;

    // Special case where slow And Fast on head 

    if(slow == fast){

        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }else{
        Node* prev = fast;

        while(slow != fast){
            prev = fast;
            slow = slow->next;
            fast = fast->next;

        }

        prev->next = NULL;
    }
    cout<<"Cycle Removed"<<endl;
    return;

   }
   
};


int main(){
    List ll;
    ll.push_front(12);
    ll.push_front(13);
    ll.push_front(14);
    ll.push_front(15);
    ll.push_front(16);
    ll.printList();
    // Creating a Cycle in linked list

    ll.Tail->next = ll.Head;
    // bool ans = ll.isCycle(ll.Head);
    // if(ans){
    //     cout<<"Cycle Detected"<<endl;
    // }else{
    //     cout<<"Cycle Not Present"<<endl;
    // }
    ll.removeCycle(ll.Head);
    ll.printList();
}