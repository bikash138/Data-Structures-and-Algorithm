#include<vector>
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

TreeNode* solve(vector<int> &inorder, int s, int e) {
    if(s>e) {
        return nullptr;
    }
    
    /*
        As the array is sorted we can use inorder to build the tree
        Mid element of the array will be the root as the it is 
        given that the height of the tree is balanced
    */

    int mid = (s+e)/2;
    int element = inorder[mid];
    TreeNode* root = new TreeNode(element);
    // Call recursively for the left subtree from 0 -> mid-1
    root->left = solve(inorder, s, mid-1);
    // Call recursively for the right subtree from mid -> end
    root->right = solve(inorder, mid+1, e);
    return root; 
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    TreeNode* root = solve(nums, start, end);
    return root;
}