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
        root->left = insert(root->left,val);
    }

    if(val > root->data){
        root->right = insert(root->right, val);
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


Node* getInOrderSuccessor(Node* root){
    while(root->left != NULL){
        root =  root->left;
    }

    return root;
}
Node* deleteNode(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = deleteNode(root->left,val);
    }

    else if(val > root->data){
         root->right = deleteNode(root->right, val);
    }else{

        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL || root->right ==  NULL){
            return root->left == NULL? root->right : root->left;
        }
        
            Node* IS = getInOrderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right , IS->data);
            return root;
        
    }
    return root;
}

void inOrder(Node* root){
    if(root == NULL){
        return ;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){

    int arr[] = {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);
    inOrder(root);
    cout<<endl;
    deleteNode(root,6);

    inOrder(root);
    cout<<endl;
}