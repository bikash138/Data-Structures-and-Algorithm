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
    void solve(TreeNode* root, int target, int sum, vector<int> temp, vector<vector<int>> &ans) {
        if(root == NULL) {
            return;
        }

        // current node
        sum = sum + root->val;
        temp.push_back(root->val);

        //leaf node
        if(root->left == NULL && root->right == NULL) {
            if(sum == target) {
                ans.push_back(temp);
                return;
            }
        }

        solve(root->left, target, sum, temp, ans);
        solve(root->right, target, sum, temp, ans);

        // No need to pop the temp vector's data as we have taken the vector by value
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;

        solve(root, targetSum, sum , temp, ans);
        return ans;
    }
};