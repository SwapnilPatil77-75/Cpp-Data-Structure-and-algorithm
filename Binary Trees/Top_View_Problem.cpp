#include<iostream>
#include<vector>
#include<queue>
#include<map>
//#include<pair>
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

void topView(Node* root){
    queue<pair<Node*,int>> Q;
    map<int,int> m;


    Q.push(make_pair(root,0));
    while(!(Q.empty())){
        pair<Node*,int> currPair = Q.front();
        Q.pop();

        Node* currNode = currPair.first;
        int  currHD = currPair.second;

        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL){
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }

        if(currNode->right != NULL){
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }

    }

    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> nodes = {1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};

    Node* root = buildTree(nodes);
   //s inOrder(root);
    topView(root);
}