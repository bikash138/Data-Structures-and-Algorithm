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
    int getIndex(int element, vector<int> arr) {
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postIndex) {
        if(postIndex < 0) {
            return NULL;
        }
        if(inStart > inEnd) {
            return NULL;
        }
        int element = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(element);
        int elementINdexInsideInorder = getIndex(element, inorder);

        // Right subtree must be built first as it is postorder
        root->right = buildTree(inorder, postorder, elementINdexInsideInorder + 1, inEnd, postIndex);
        root->left = buildTree(inorder, postorder, inStart, elementINdexInsideInorder - 1, postIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        int postIndex = postorder.size() - 1;
        TreeNode* root = buildTree(inorder, postorder, inStart, inEnd, postIndex);
        return root;
    }
};