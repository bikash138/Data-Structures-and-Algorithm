#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
  public:

  //We are using unordered_map because it allows the lookups in O(1) while ordered maps do it in O(log n)
  unordered_map<int, list<int> > adjList;

  void addEdge(int u, int v, bool direction){
    // u-> 1st Node, v-> 2nd Node
    // direction -> 0 -> undirected graph
    // direction -> 1 -> directed graph
    if(direction == 1){
      //That means we have a edge from u towards v
      //So add v node to the list of u
      adjList[u].push_back(v);
    }else{
      //direction-> 0
      // both u->v and v->u are possible
      //Add both u and v node in each others adjList
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
};

int main() {
  Graph g;
  g.addEdge(0,1,1);
  g.addEdge(1,2,1);
  g.addEdge(1,3,1);
  g.addEdge(2,3,1);
  g.addEdge(3,4,1);
  g.addEdge(4,5,1);
  g.addEdge(5,3,1);
  g.print();
  return 0;
}