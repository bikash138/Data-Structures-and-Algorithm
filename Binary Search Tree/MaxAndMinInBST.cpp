//The leftmost Node of a BST will the smallest Node of the BST
Node* minValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node * temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;

}

//The rightmost Node of a BST will be the largest Node of the BST
Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node * temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}