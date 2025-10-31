int heightOfTree(Node *root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        int height = max(leftHeight, rightHeight) + 1;
        return height;
    }

int diameterOfTree(Node *root){
    //To find diameter we have to find the height of left subTree and right subTree
    
    int diameter = heightOfTree(root->left) + heightOfTree(root->right);
    return diameter;
}