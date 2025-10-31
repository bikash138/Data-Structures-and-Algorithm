Node* lca(Node *root, Node* p, Node* q){
    //base cases
    if(root == NULL){
        return NULL;
    }
    if(root->val == p->val){
        return p;
    }
    if(root->val == q->val){
        return q;
    }
    Node*left = lca(root->left, p, q);
    Node*right = lca(root->right, p, q);

    if(left != NULL && right == NULL){
        return left;
    }
    else if(left == NULL && right != NULL){
        return right;
    }
    else if(left == NULL && right == NULL){
        return root;
    }
    else{
        return NULL;
    }
}