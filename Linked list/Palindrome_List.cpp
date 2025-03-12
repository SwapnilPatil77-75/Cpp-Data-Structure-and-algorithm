#include<iostream>
#include<vector>
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
        Head  = newNode;
    }
    }

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
    printList();
    return;
}

    void printList(){
    Node* temp = Head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL\n";
    }
    bool isPalindrome(){
        cout<<"in Palindrome()"<<endl;
        vector<int> vec;
        int inx = 0;
        Node* temp = Head;
        while(temp != NULL){
            vec[inx] = temp->data;
            temp = temp->next;
            inx++;
        }
        for(int i = 0; i<vec.size(); i++){
            cout<<vec[i]<<" ";

        }
        cout<<"\n";

    

        Node* curr = Head;
        inx = 0;
        while(curr != NULL){
            if(vec[inx] != curr->data){
                return -1;
        }

            curr = curr->next;
            inx++;
        }
        return 1;
        }
};


int main(){
    List ll;
    ll.push_front(20);
    ll.push_front(10);
    ll.push_front(30);
    ll.printList();
    // ll.reverse();
    // ll.printList();

    cout<<ll.isPalindrome()<<endl;
    
}