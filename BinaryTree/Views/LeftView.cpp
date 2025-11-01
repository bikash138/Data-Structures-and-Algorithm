//To print the left View we need PreOrder Traversal N -> L -> R
void printLeftView(Node*root, int level, vector<int> &leftView){
    //Base Case: If node is not present return null and do nothing
    if(root == NULL){
        return;
    }
    //As the level matches the size of the array it means no new element is yet pushed hence push the root
    //As we are travelling N -> L -> R, therefore the leftmost node will be always pushed first
    //If level does not matches that means there is already a leftmost element present at that level 
    //which is already in the array that has increased the size of it
    if(level == leftView.size()){
        cout << root->data << " ";
        leftView.push_back(root->data);
    }
    //As we are printing the left View hence we will first travel from left subtree of each node
    //On every call level will be increased as we are moving downwards
    printleftView(root->left, level+1, leftView);
    printleftView(root->left, level+1, leftView);
}

int main(){
    int level = 0;
    vector<int> leftView;
    printLeftView(root, level, leftView);
}