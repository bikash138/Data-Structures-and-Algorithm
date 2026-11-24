#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int getLen(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

TreeNode* solve(ListNode* &head, int n) {
    if(head == nullptr) return nullptr;
    if(n <= 0) return nullptr;

    // LNR

    //L
    // THe first half of the tree would be left subtree
    TreeNode* leftSubtree = solve(head, n/2);
    // N
    // Create the node of the current node
    int element = head->val;
    TreeNode* root = new TreeNode(element);
    root->left = leftSubtree;
    // IMP step: update teh head for the next node
    head = head->next;
    //R
    // The other half will be 1 less because one node is used in the root
    TreeNode* rightSubtree = solve(head, n-n/2-1);
    root->right = rightSubtree;
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    // Get the length of the LInked list
    int len = getLen(head);
    TreeNode* root = solve(head, len);
    return root;
}