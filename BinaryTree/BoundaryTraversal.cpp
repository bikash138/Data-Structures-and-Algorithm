//There are three parts while printing the boundary elements
//A -> All the left Nodes till leaf node is found
//B-> All the leaf nodes
//C-> All the rightmost nodes

void printLeftBoundary(Node *root){
    if(root == NULL){
        return;
    }
    //Leaf Node Found
    if(root->left == NULL && root->right == NULL){
        return;
    }
    //Valid Node Found hence print it -> This also prints the Root of the tree 
    cout << root->data;
    //Print the left Node if available
    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    //If root->left is not present then root->right will be the leftmost node
    else{
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root){
    if(root == NULL){
        return;
    }
    //If the do not have any child then its a leaf node hence print it
    if(root->left == NULL && root->right == NULL){
        cout << root->data;
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRIghtBoundary(Node *root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    //First priority is the root->right if it is not present then move to root left as it will be rightmost node
    if(root->right != NULL){
        printRightBoudnary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
    //Printing the ndoe at last ensures that the printing takes place from down to top while the backtracking
    cout << root->data;
}

void boundaryTraversal(Node *root){
    if(root == NULL){
        return;
    }
    //Print the left boundary(including the root Node) and the leaf nodes
    printLeftBoundary(root);
    printLeafBoundary(root);
    //This condition ensures the root node don't gets printed twice because it has been already handled in the Left Boundary
    //So here we are only calling the printRightBoundary() with the root->right node directly not with root
    if(root->right != NULL){
        printRightBoundary(root->right);
    }
    else{
        printRightBoundary(root->left);
    }
}