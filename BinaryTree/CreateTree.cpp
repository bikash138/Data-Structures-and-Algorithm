#include<iostream>
#include <queue>
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
    cout << "Enter left child of " << data << endl;
    root->left = createTree();
    cout << "Enter right child of " << data << endl;
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

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    //Push the root of the tree in the queue initially
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

#include<map>
#include<queue>

void printTopView(Node *root){
    //Create a map to store the horizontal distance to node mapping
    map<int, int> hdToNodeMapping;
    //Create a queue which will store a pair of node and the horizontal distance
    queue< pair<Node*, int> > q;
    //Initially push the root node in the queue
    q.push(make_pair(root, 0));
    
    //Now we will do Level Order Traversal
    while(!q.empty()){
        //Takeout the front element 
        pair<Node*, int> temp = q.front();
        q.pop();

        //Destructure the element as it is a pair
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        //map.find() -> Returns the pointer if the key(hd) is present
        //map.end() -> It itself gets returned if the key(hd) is not found
        //Hence, if map.find(hd) == map.end() means key not found
            //If key not found, then create one and map it to frontNode ka data
            //As it if top view hence at every hd only first found Node will be stored
            //hence we are not overwriting the mapping after being created once
            hdToNodeMapping[hd] = frontNode->data;
        
        //Now process the child of the frontNode
        if(frontNode->left != NULL){
            //Now push the left child of frontNode and decrement the hd
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            //Now push the right child of frontNode and increment the hd
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "Printing the Top View:" << endl;
    for(auto i:hdToNodeMapping){
        cout << i.second << " ";
    }
}

int main(){
    Node *root = createTree();
    // printPreOrder(root);
    // printInOrder(root);
    // printPostOrder(root);
    // levelOrderTraversal(root);
    printTopView(root);
    return 0;
}