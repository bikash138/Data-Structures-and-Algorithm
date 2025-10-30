#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        //Making the left and right of Node type
        Node *left;
        Node *right;

        //Parameterised Constructor
        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
    
};

Node *createTree(){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    //If user give -1 then it is the leaf node
    if(data == -1){
        return NULL;
    }
    //Create root node with the data
    Node *root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void printPreOrder(Node *root){
    if(root == NULL){
        return;
    }
    //NLR
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node *root){
    if(root == NULL){
        return;
    }
    //LNR
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node *root){
    if(root == NULL){
        return;
    }
    //LRN
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main(){
    Node *root = createTree();
    printPreOrder(root);
    printInOrder(root);
    printPostOrder(root);
    cout << endl;
    return 0;
}