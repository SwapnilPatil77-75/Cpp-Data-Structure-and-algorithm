#include<bits/stdc++.h>
#include<queue>
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

int noOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftNodes = noOfNodes(root->left);
    int rightNodes = noOfNodes(root->right);

    int curr = leftNodes + rightNodes + 1;

    return curr; 
}





int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,7,-1,-1};
    Node* root = buildTree(nodes);
    cout<<noOfNodes(root)<<endl;
}