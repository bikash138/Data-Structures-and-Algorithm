#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void storeInorder(TreeNode* root, vector<int> &inorder) {
    if(root ==  NULL) return;

    storeInorder(root->left, inorder);
    inorder.push_back(root->val);
    storeInorder(root->right, inorder);
}

void updateTree(TreeNode* root, vector<int> inorder, int &index) {
    if(root == NULL) {
        return;
    }
    // LNR
    updateTree(root->left, inorder, index);
    root->val = inorder[index];
    index++;
    updateTree(root->right, inorder, index);
}

TreeNode* convertBST(TreeNode* root) {
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) {
        return root;
    }
    // Step 1: Store inorder
    vector<int> inorder;
    storeInorder(root, inorder);
    // Step 2: Update inorder as per question
    int n = inorder.size();
    for(int i=n-1; i >= 0; i--) {
        int currVal = inorder[i];
        int nextVal = 0;
        if(i+1 < n) {
            nextVal = inorder[i+1];
        }
        int sum = currVal + nextVal;
        inorder[i] = sum;
    }
    // Step 3: Update tree
    int index = 0;
    updateTree(root, inorder, index);
    return root;
}
