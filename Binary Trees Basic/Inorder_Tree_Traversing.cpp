#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

static int inx = -1;
Node* buildTree(vector<int> nodes){

inx++;
if(nodes[inx] == -1){
    return NULL;
}


Node* newNode = new Node(nodes[inx]);
newNode->left = buildTree(nodes);
newNode->right = buildTree(nodes);

return newNode;
};


void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


int main(){
    vector<int> nodes1 = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes2 = {2,4,-1,-1,5,-1,-1};
    Node* root = buildTree(nodes1);
    inOrder(root);
    Node* root2 = buildTree(nodes2);
    inOrder(root2);
}