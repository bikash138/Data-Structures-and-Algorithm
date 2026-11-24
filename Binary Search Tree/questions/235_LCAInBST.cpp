using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// APPROACH 1: Using simple binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) {
        return nullptr;
    }
    if(root->val == p->val){
        return p;
    }
    if(root->val == q->val) {
        return q;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left == nullptr && right == nullptr) {
        return nullptr;
    }
    else if(left != nullptr && right == nullptr) {
        return left;
    }
    else if(left == nullptr && right != nullptr) {
        return right;
    }
    else return root;
}

// APPROACH 2: Using the property Of BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) {
        return nullptr;
    }
    // case A: p and q are both on left side
    // right is neglected and left is selected
    if(p->val < root->val && q->val < root->val) {
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        if(leftAns != nullptr) {
            return leftAns;
        }
    }
    // case B: p and q are both on right side
    if(p->val > root->val && q->val > root->val) {
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        if(rightAns != nullptr) {
            return rightAns;
        }
    }
    // case C: p and q are on different subtree
    return root;
}