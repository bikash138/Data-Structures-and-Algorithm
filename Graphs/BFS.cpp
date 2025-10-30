using namespace std;
#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>

class Graph{
    public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v, bool direction){
        if(direction == 1){
            adjList[u].push_back(v);
        }
        else{  
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }
    }

    void print(){
        //Iteration over adjList gives a pair of int and list
        for(auto pair: adjList){
            //pair.first gives the u node
            cout << pair.first << " -> ";
            //pair.second gives the list of all neigbor nodes
            for(auto nbr: pair.second){
                cout << nbr << ", ";
            } 
            cout << endl;
        }
    }

    void BFStraversal(int src, unordered_map<int, bool> &vis){
        //Create the queue
        queue<int> q;

        //Set the intial data
        q.push(src);
        vis[src] = true;

        //Push the new nodes into the queue
        while(!q.empty()){
            //Perform the required operation here
            //Front node will give the nodes in breadth first manner
            int frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            //Iterate over the adjList[frontNode] to get all the nbr of that node
            for(auto nbr: adjList[frontNode]){
                //If it visited then skip it else push that node to the queue and mark it as true
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
    }

    void DFStraversal(int src, unordered_map<int, bool> &vis){
        vis[src] = true;
        cout << src << " ";

        for(auto nbr: adjList[src]){
            //This condition automatically becomes the base case 
            //Once all the nodes are visited then the recursive call will never run and the base case automatically reached
            if(!vis[nbr]){
                DFStraversal(nbr, vis);
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(4,5,0);
    g.addEdge(6, 7,0);
    // g.print();
    unordered_map<int, bool> visited;
    for(int node=1; node<=6; node++){
        if(!visited[node]){
            g.DFStraversal(node, visited);
        }
    }
    // g.BFStraversal(1,visited);
    return 0;
}