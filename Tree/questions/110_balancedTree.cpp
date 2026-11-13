#include<iostream>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int getHeight(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftDepth = getHeight(root->left);
        int rightDepth = getHeight(root->right);
        int ans = max(leftDepth, rightDepth) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            //empty tree is considered as balanced
            return true;
        }

        // current Node ka ans
        int leftHeight = getHeight(root->left);
        int rightHeight= getHeight(root->right);
        int absDiff = abs(leftHeight - rightHeight);
        if(absDiff > 1) {
            //not balanced
            return false;
        } else {
            //current node is balanced
            // left ans
            bool leftAns = isBalanced(root->left);
            //right ans
            bool rightAns = isBalanced(root->right);
            if(leftAns == true && rightAns == true) {
                return true;
            }
            else {
                return false;
            }
        }
    }
};