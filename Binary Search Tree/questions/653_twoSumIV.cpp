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
    if(root == NULL) return;

    // LNR
    storeInorder(root->left, inorder);
    inorder.push_back(root->val);
    storeInorder(root->right, inorder);
}
bool checkTwoSum(vector<int> arr, int target) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s < e) {
        int sum = arr[s] + arr[e];
        if(sum == target) return true;
        else if (sum > target) e--;
        else s++;
    }
    return false;
}
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    storeInorder(root, inorder);
    bool ans = checkTwoSum(inorder, k);
    return ans;
}
