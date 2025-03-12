#include<iostream>
#include<vector>
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
    vector<int> vec;
    int inx = 0;
    void reverse(){
    Node* prev = NULL;
    Node* curr = Head;
    vec[inx] = curr->data;
    inx++;
    Node* Next = Head->next;

    while(curr != NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        vec[inx] = curr->data;
        cout<<vec[inx];
        inx++;
    }
    for(int i = 0; i<vec.size(); i++){
        cout<<vec[i]<<endl;
    }

    Head = prev;
    cout<<isPalindrome(vec);
    }

    bool isPalindrome(vector<int> &vec){
        Node* temp = Head;
        int ind = 0;
        int count = 0;
        while(temp != NULL){
            if(vec[ind] == temp->data){
                count++;
                temp = temp->next;
                ind++;
            }
        }
        if(count == 0){
            return true;
        }
        else{
            return false;
        }
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

    ll.printList();
    ll.reverse();
    ll.printList();
}