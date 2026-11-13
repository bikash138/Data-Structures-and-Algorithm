#include<iostream>
#include<vector>
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
  
    void leftBoundary(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            return;
        }
        
        if(root->left == NULL && root->right == NULL) {
            return;
        }
        //store the ans
        ans.push_back(root->data);
        // go to left until possible
        if(root->left != NULL) {
            leftBoundary(root->left, ans);
        }
        else {
            leftBoundary(root->right, ans);
        }
    }
    
    void leafBoundary(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
    }
    
    void rightBoundary(TreeNode* root, vector<int> &ans) {
        if(root == NULL) {
            return;
        }
        
        if(root->left == NULL && root->right == NULL) {
            return;
        }
        
        if(root->right != NULL) {
            rightBoundary(root->right, ans);
        }
        else {
            rightBoundary(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(TreeNode *root) {
        // code here
        vector<int> ans;
        
        //root
        if(root == NULL) {
            return ans;
        }
        else {
            ans.push_back(root->data);
        }
        
        //left boundary -> nor root and no leaves
        leftBoundary(root->left, ans);
        // left leaves
        leafBoundary(root->left, ans);
        // right leaves
        leafBoundary(root->right, ans);
        //right boundary
        rightBoundary(root->right, ans);
        
        return ans;
        
    }
};