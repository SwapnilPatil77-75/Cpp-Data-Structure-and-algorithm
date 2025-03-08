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

Node* deleteLeaf(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    Node* leftval = deleteLeaf(root->left, key);
    Node* rightval = deleteLeaf(root->right, key);

    if(leftval == NULL && rightval == NULL && root->data == key){
        return NULL;
        
    }

    root->left = leftval;
    root->right = rightval;
    return root;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,-1,3,2,4,-1,-1,-1,4,-1,-1};

    Node* root = buildTree(nodes);
    inOrder(root);
    cout<<endl;
    
    

    Node* root2 = deleteLeaf(root,2);
    inOrder(root2);
   
    
    
}