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