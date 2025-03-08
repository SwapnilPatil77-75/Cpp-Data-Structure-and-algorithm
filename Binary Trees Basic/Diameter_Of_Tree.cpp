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

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHgt = height(root->left);
    int rightHgt = height(root->right);

    int curr = max(leftHgt,rightHgt)+1;

    return curr;
}


int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int curr = height(root->left) + height(root->right);

    int left = diameter(root->left);
    int right = diameter(root->right);

    
    // int temp = max(left,right);
    // return max(temp,curr);
    return max(curr,max(left,right));
}





int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,7,-1,-1};
    Node* root = buildTree(nodes);
    cout<<diameter(root)<<endl;
}