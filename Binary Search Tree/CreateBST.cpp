#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
    BST is a binary tree whose value of all the nodes in the left subtree
    will be smaller than the root node and all the nodes in the right subtree
    is greater than the root node. 
*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    //1st case-> Create the root the BST
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    //2nd case-> Root already created hence create the subtree
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }else{
        root->left = insertIntoBST(root->left, data);
    }
}

void preOrder(Node* root) {
    // NLR
    if(root == NULL) {
        return;
    }
    //NLR
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// INORDER of BST is always sorted
void inOrder(Node* root) {
    // LNR
    if(root == NULL) {
        return;
    }
    //LNR
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

void postOrder(Node* root) {
    // LRN
    if(root == NULL) {
        return;
    }
    //NLR
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            //We need to change the line
            cout << endl;
            // IF q is not empty that means child nodes are still  there
            if(!q.empty()) {
                q.push(NULL);
            }
        } 
        else {
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}