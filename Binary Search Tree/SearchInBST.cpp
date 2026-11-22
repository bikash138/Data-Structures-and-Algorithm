using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool searchInBST(Node* root, int target){
    //Base Case-> If root is NULL
    if(root == NULL){
        return false;
    }
    //If target found the return true
    if(root->data == target){
        return true;
    }
    //Intialise the leftAns and rightAns
    bool leftAns = false; bool rightAns = true;
    //Now choose the subtree to seach the target
    if(target > root->data){
        rightAns = searchInBST(target, root->right);
    }
    else{
        leftAns = searchInBST(target, root->left);
    }
    return leftAns || rightAns;
}