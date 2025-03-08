#include<iostream>
#include<vector>
#include<queue>
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

static int inx = -1;
Node* buildTree(vector<int> nodes){
inx++;

if(nodes[inx] == -1){
    return NULL;
}

Node* newNode = new Node(nodes[inx]);
newNode->left = buildTree(nodes);
newNode->right = buildTree(nodes);
}

void printKthLevel(Node* root,int k){
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    int j = 1;
    while(!(Q.empty())){
        Node* curr = Q.front();
        Q.pop();


        if(curr == NULL){
            
            if(j == k){
                Node* temp = Q.front();
                while(temp != NULL){
                    cout<<temp->data<<" ";
                    Q.pop();
                    temp = Q.front();
                }
            }
            j++;

            if(Q.empty()){
                break;
            }

            Q.push(NULL);
        }else{
            if(curr->left != NULL){
                Q.push(curr->left);
            }

            if(curr->right != NULL){
                Q.push(curr->right);
            }
        }
    }


}

void inOrder(Node* root){
    if(root== NULL){
        return;
    }


    inOrder(root->left);
    cout<<root->data<<endl;
    inOrder(root->right);
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    printKthLevel(root,1);
    inOrder(root);

}