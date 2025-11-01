//To print the right View we need PreOrder Traversal N -> R -> L
void printRightView(Node*root, int level, vector<int> &rightView){
    //Base Case: If node is not present return null and do nothing
    if(root == NULL){
        return;
    }
    //As the level matches the size of the array it means no new element is yet pushed hence push the root
    //As we are travelling N -> R -> L, therefore the rightmost node will be always pushed first
    //If level does not matches that means there is already a rightmost element present at that level 
    //which is already in the array that has increased the size of it
    if(level == rightView.size()){
        cout << root->data << " ";
        rightView.push_back(root->data);
    }
    //As we are printing the right View hence we will first travel from right subtree of each node
    //On every call level will be increased as we are moving downwards
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}

int main(){
    int level = 0;
    vector<int> rightView;
    printRightView(root, level, rightView);
}