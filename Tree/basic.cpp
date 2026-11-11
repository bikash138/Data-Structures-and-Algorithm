#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    int val;
    cin >> val;

    if(val == -1) {
        return NULL;
    }
    else {
        Node* root = new Node(val);
        // OTher will be handled by recursion
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}

// NLR - preorder
void preOrderTraversal(Node* root) {
    // Base Case
    if(root == NULL) {
        return;
    }
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

// LNR - inorder
void inOrderTraversal(Node* root) {
    // Base Case
    if(root == NULL) {
        return;
    }
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

// LRN - post order
void postOrderTraversal(Node* root) {
    // Base Case
    if(root == NULL) {
        return;
    }
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

// Level ORder Traversal

void levelOrderTraversal(Node* root) {
    // empty tree
    if(root == NULL) return;

    queue<Node*> q;

    //inital state
    q.push(root);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        cout << front->data;

        if(front->left != NULL) {
            q.push(front->left);
        }

        if(front->right != NULL) {
            q.push(front->right);
        }
    }
}

int main () {
    Node* root = buildTree();
    cout << endl;

    cout << "Printing Preorder Traversal: " << endl;
    preOrderTraversal(root);

    cout << endl;

    cout << "Printing Postorder Traversal: " << endl;
    postOrderTraversal(root);

    cout << endl;

    cout << "Printing Inorder Traversal: " << endl;
    inOrderTraversal(root);

    cout << "Printing Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}

// T.C of all types of traversal -> O(n) as we are travelling on all the nodes 