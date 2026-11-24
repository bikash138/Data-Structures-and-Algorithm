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

// APPROACH 1: Using Inorder
class Solution {
public:
    void storeInorder(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) {
            return;
        }
        //LNR
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);
        return inorder[k-1];
    }
};

// APPROACH 2: Using Recursion
/*
    1. We will traverse the tree in inorder
    2. When we reach the node we will increase the count
    3. When the count becomes equal to k that means that is our answer
    4. We will store that node in the ans 
*/
void solve(TreeNode *root, int k, int &count, TreeNode* &ans) {
    if(root == NULL) {
        return;
    }
    // LNR
    solve(root->left, k, count, ans);
    count++;
    if(count == k) {
        ans = root;
    }
    solve(root->right, k, count, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    TreeNode* ans = NULL;
    solve(root, k, count, ans);
    return ans->val;
}