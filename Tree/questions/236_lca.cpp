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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root == NULL) {
        return NULL;
      }
      if(root == p) {
        return p;
      }
      if(root == q) {
        return q;
      }

      TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
      TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

      if(leftAns == NULL && rightAns == NULL) {
        return NULL;
      }
      else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
      }
      else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
      }
      else {
        //current node is the LCA
        return root;
      }
  }
};