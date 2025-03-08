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

int height(Node* root ,int &maxi){
    if(root == NULL){
        return 0;
    }

    int h1 = max(0,height(root->left,maxi));
    int h2 = max(0,height(root->right, maxi));

     maxi = max(maxi, h1+h2+root->data);

    return root->data +  max(h1,h2);
}

int maxPathSum(Node* root ){
    int res = INT32_MIN;

    height(root,res);
    return res;
}


int main(){
    vector<int> nodes = {-10,9,-1,-1,20,15,-1,-1,7,-1,-1};

    Node* root = buildTree(nodes);
    inOrder(root);
    cout<<endl;
    cout<<maxPathSum(root);
    
    

    
   
    
    
}