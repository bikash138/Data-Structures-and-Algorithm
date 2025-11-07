//For deleting a node in a BST we have three scenarios
//1st Case -> The node to be deleted has no children
//2nd Case -> The node to be deleted has single children
//**3rd Case -> The node to be deleted has both the children

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

Node* deleteNodeFromBST(Node* root, int target){
    //First find the node to be deleted
    if(root == NULL){
        return NULL;
    }
    else if(target < root->data){
        //For a valid BST the left node is smaller than root node
        root->left = deleteNodeFromBST(root->left, target);
    }
    else if(target > root->data){
        //For a valid BST the right node is greater than root node
        root->right = deleteNodeFromBST(root->right, target);
    }
    else(root->data == target){
        //Here the target has been found
        //1st case - leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //2nd case - root has only right child
        else if(root->right != NULL && root->left == NULL){
            Node* child = root->right;
            delete root;
            return child;
        }
        //2nd case - root has only left child
        else if(root->right == NULL && root->left != NULL){
            Node* child = root->left;
            delete root;
            return child;
        }
        //3rd case - root has both children
        else{
            Node* maxi = maxValue(root->left);
            root->data = maxi->data;
            root->left = deleteNodeFromBST(root->left, maxi->data);
            return root;
        }
    }
}