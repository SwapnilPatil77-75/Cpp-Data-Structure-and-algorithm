#include<iostream>
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

Node* insert(Node* root , int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val > root->data){
        root->right = insert(root->right, val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }

    return root;
}
Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i = 0; i<n; i++){
        root = insert(root, arr[i]);
    }

    return root;
}

void printInRange(Node* root, int st , int en){
    if(root == NULL){
        return;
    }

    if( root->data >= st && root->data <= en){
        cout<<root->data<<" ";
        printInRange(root->left, st, en);
        printInRange(root->right, st, en);
    }

    if(root->data < st){
        printInRange(root->right, st,en);

    }else{
        printInRange(root->left,st,en);
    }

    
}

int main(){
    int arr[] = {5,1,3,4,2,7};

    Node* root = buildBST(arr, 6);

    printInRange(root,3,5);


}