#include <climits>

//This Question can be solved by checking the inorder of the tree is sorted or not 
bool validateBST(Node* root, long long lowerbound, long long upperbound){
    //Base Case - Empty tree is always a valid BST
    if(root == NULL){
        return true;
    }
    
    //Check for MAX and MIN limits using the uperbound and lowerbound 
    bool cond1 = (root->data > lowerbound);
    bool cond2 = (root->data < upperbound);

    //Now the check the BST PRoperty
    //Check if the left subtree has upperbound of Root -> Left should be less than root
    bool leftAns = validateBST(root->left, lowerbound, root->data);
    //Check if the right subtree has lowerbound of Root -> Right should be greater than root
    bool rightAns = validateBST(root->right, root->data, upperbound);

    //If the Node is in the range and following the left and right subtree condition then it is a valid BST
    if(cond1 && cond2 && leftAns && rightAns){
        return true;
    }else{
        return false;
    }
}

bool main(){
    //Reason for using LLONG_MAX/MIN -> Each node of BST is a int 
    //So it can be the last limit of INT_MIN/MAX so doing INT_MAX+1 or INT_MIN-1 will cause out of limit error
    //Hence we are using LLONG for increasing the limit so that the last int value can be handled 
    long long upperbound = LLONG_MAX;
    long long lowerbound = LLONG_MIN;
    bool ans = validateBST(root, lowerbound, upperbound);
    return ans;
}