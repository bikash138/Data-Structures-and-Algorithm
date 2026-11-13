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
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder, int &preOrderIndex, int inOrderStart, int inOrderEnd) {
        if(preOrderIndex >= preOrder.size()) {
            return NULL;
        }
        if(inOrderStart > inOrderEnd) {
            return NULL;
        }

        int element = preOrder[preOrderIndex];
        preOrderIndex++;

        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = getIndex(element, inOrder);
        root->left = buildTree(preOrder, inOrder, preOrderIndex, inOrderStart, elementIndexInsideInorder-1);
        root->right = buildTree(preOrder, inOrder, preOrderIndex, elementIndexInsideInorder+1, inOrderEnd);
        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size() - 1;
        TreeNode* root = buildTree(preorder, inorder, preOrderIndex, inOrderStart, inOrderEnd);
        return root;
    }
};