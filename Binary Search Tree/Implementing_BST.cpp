#include<iostream>
#include<vector>
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



Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }


    if(val<root->data){
        root->left = insert(root->left, val);
    }

    if(val > root->data){
        root->right = insert(root->right, val);
    }

    return root;
}
Node* buildBST(int nodes[], int n){

    Node* root = NULL;   // 5

    for(int i = 0; i<n; i++){
        root = insert(root,nodes[i]);
    }

    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    // cout<<root->data<<" ";
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

int main(){

int nodes[6] = {5,1,3,4,2,7};
int n = sizeof(nodes)/sizeof(nodes[0]);

Node* root = buildBST(nodes, 6);
preOrder(root);
cout<<endl;
cout<<7/10<<endl;
}