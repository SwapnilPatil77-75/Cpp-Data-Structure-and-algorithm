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

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> nodes ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);

    preOrder(root);

}