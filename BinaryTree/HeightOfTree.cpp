int heightOfTree(Node *root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    // 1 is added as we have missed the addition of root node in the height
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}