#include<iostream>
#include<vector>
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
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

Node* invertTree(Node* root){
    if(root == NULL){
        return NULL;
    }


   Node* left1 =  invertTree(root->left);
   Node* right1 = invertTree(root->right);
   

   root->left = right1;
   root->right = left1;


   return root;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    inOrder(root);
    cout<<endl;

    Node* root2 = invertTree(root);
    inOrder(root2);
}