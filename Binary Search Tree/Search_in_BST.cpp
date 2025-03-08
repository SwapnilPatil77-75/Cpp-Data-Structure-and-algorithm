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

Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }


    if(val < root->data){
        root->left = insert(root->left, val);
    }

    if(val> root->data){
        root->right = insert(root->right,val);
    }

    return root;
}


Node* buildBST(int arr[], int n){

    Node* root = NULL;

    for(int i = 0; i<n; i++){
        root = insert(root,arr[i]);
    }


    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }


    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


bool Search(Node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data < key){
        return Search(root->right,key);
    }

    if(root->data > key){
        return Search(root->left, key);
    }


    return false;
}
int main(){
    int arr[] = {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);

    inOrder(root);
    cout<<"\n";
    cout<<Search(root, 5);
}