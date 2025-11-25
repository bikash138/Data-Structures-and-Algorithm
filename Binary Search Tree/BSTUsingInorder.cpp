// This algo only works if the inorder is sorted and there is no duplicate nodes

Node* BSTUsingInorder(int inorder[], int s, int e){
    //base case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    //Recursion
    root->left = BSTUsingInorder(inorder, s, mid-1);
    root->right = BSTUsingInorder(inorder, mid+1, e);

    return root;
}

int main (){
    int inorder[7] = {10, 20, 30, 40, 50, 60, 70};
    int s = 0;
    int e = 7
    Node* rootOfBST = BSTUsingInorder(inorder, s, e); 
    return 0;
}