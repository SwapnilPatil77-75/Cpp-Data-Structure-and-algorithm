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
if(nodes[inx]== -1){
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


bool isEquilised(Node* root){
    if(root== NULL){
        return 1;
    }

    if(!(isEquilised(root->left) || !(isEquilised(root->right)))){
        return false;
    }

    if(root->left != NULL){
        if(root->data != root->left->data){
            return false;
        }
    }

    if(root->right != NULL){
        if(root->data != root->right->data){
            return false;
        }
    }

    return true;
}

int main(){
    vector<int> nodes = {1,2,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1};

    Node* root = buildTree(nodes);
    inOrder(root);
    cout<<endl;
    cout<<isEquilised(root)<<endl;
    
}