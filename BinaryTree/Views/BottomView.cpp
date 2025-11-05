#include<map>
#include<queue>

void printTopView(Node *root){
    //Create a map to store the horizontal distance to node mapping
    map<int, int> hdToNodeMapping;
    //Create a queue which will store a pair of node and the horizontal distance
    queue< pair<Node*, int> > q;
    //Initially push the root node in the queue
    q.push(make_pair(root, 0));
    
    //Now we will do Level Order Traversal
    while(!q.empty()){
        //Takeout the front element 
        pair<Node*, int> temp = q.front();
        q.pop();

        //Destructure the element as it is a pair
        Node* frontNode = temp.first;
        int hd = temp.second;
        
        //map.find() -> Returns the pointer if the key(hd) is present
        //map.end() -> It itself gets returned if the key(hd) is not found
        //Hence, if map.find(hd) == map.end() means key not found
            //If key not found, then create one and map it to frontNode ka data
            //As it if top view hence at every hd only first found Node will be stored
            //hence we are not overwriting the mapping after being created once
            hdToNodeMapping[hd] = frontNode->data;
        
        //Now process the child of the frontNode
        if(frontNode->left != NULL){
            //Now push the left child of frontNode and decrement the hd
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            //Now push the right child of frontNode and increment the hd
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout << "Printing the Top View:" << endl;
    for(auto i:hdToNodeMapping){
        cout << i.second << " ";
    }
}