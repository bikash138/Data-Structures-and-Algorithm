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

//For deleting a node in a BST we have three scenarios
//1st Case -> The node to be deleted has no children
//2nd Case -> The node to be deleted has single children
//**3rd Case -> The node to be deleted has two children

class Solution {
public:

    int  getMax(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        while(root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == key) {
            // Target found
            // Ther will be 4 cases here to delete a node
            // 0 child
            if(root->left == NULL && root->right == NULL) {
                TreeNode* temp = root;
                delete temp;
                return NULL;
            }
            //1 child on left
            if(root->left != NULL && root->right == NULL) {
                TreeNode* temp = root;
                TreeNode* child = root->left;
                temp->left = NULL;
                delete temp;
                return child;
            }
            //1 child right
            if(root->left == NULL && root->right != NULL) {
                TreeNode* temp = root;
                TreeNode* child = root->right;
                temp->right = NULL;
                delete temp;
                return child;
            }
            // 2 child
            if(root->left != NULL && root->right != NULL) {
                // We will replace the root node with the max value of left subtree
                int replaceValue = getMax(root->left);
                root->val = replaceValue;
                // Second Step: deletion
                root->left = deleteNode(root->left, replaceValue);
                return root;
            }
            
        }
        else {
            // Target not found
            // Then we need to search the node using BST property
            if(key > root->val) {
                // Node must be on the right side
                root->right = deleteNode(root->right, key);
            }
            else {
                // Node must be on the left side
                root->left = deleteNode(root->left, key);
            }
        }
        return root;
    }
};