#include<bits/stdc++.h>
#include<vector>
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

static int inx = -1;   // static index to manage the current index while recursively calling 

Node* buildTree(vector<int> nodes){

    inx++;

    if(nodes[inx] == -1){
        return NULL;
    }
    Node* currNode = new Node(nodes[inx]);
    currNode->left = buildTree(nodes);  // call for root Left Subtree
    currNode->right = buildTree(nodes); // call for root Right Subtree


    return currNode;

}


bool helper(Node* root1 , Node* root2){
   if(root1 == NULL && root2 == NULL){
    return true;
   }else if(root1 == NULL || root2 == NULL){
    return false;
   }


   return helper(root1->left, root2->left) && helper(root1->right, root2->right);
}

bool isIndentical(Node* root1 , Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }

    if(root1->data == root2->data){
        if(helper(root1, root2)){
            return 1;
        }

    }
    // check if Subroot Is present in LeftSubroot
    int leftroot = isIndentical(root1->left, root2);
    // Otherwise check in right Subroot 
    if(!leftroot){
        return isIndentical(root1->right, root2);
    }

    return -1;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    vector<int> nodes1={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes2={2,4,-1,-1,5,-1,-1};

    Node* root1 = buildTree(nodes1);
    Node* root2 = buildTree(nodes2);

    inorder(root1);
   // inorder(root2);

    //cout<<isIndentical(root1, root2)<<endl;
    
}