#include<bits/stdc++.h>
using namespace std;


class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }


};

static int inx = -1;   // static index to manage the current index while recursively calling 

Node* buildTree(vector<int> nodes){

    inx++;

    if(nodes[inx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[inx]);
    currNode->left = buildTree(nodes);  // call for root Left Subtree
    currNode->right = buildTree(nodes); // call for root Right Subtree


    return currNode;

}


int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    cout<<root->data<<endl;  //1
    root = root->left;
    cout<<root->data<<endl; //2
    root = root->right;
    cout<<root->data<<endl;// 5
}