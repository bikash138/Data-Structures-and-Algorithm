#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
  public:
  // For Weighted Graphs we will again use unordered_map but with list of pairs<node, weights>
  unordered_map< int, list< pair<int,int> > > adjList;
  
  void addEdge(int u, int v, bool direction, int wt){
    // direction -> 0 -> undirected graph
    // direction -> 1 -> directed graph
    if(direction == 1){
      adjList[u].push_back({v,wt});
    }
    else{
      adjList[u].push_back({v,wt});
      adjList[v].push_back({u,wt});
    }
  }
  void print(){
    for(auto pair: adjList){
      cout << pair.first << "-> ";
      //Here nbr is a pair not a simple value so handle it properly
      for(auto nbr: pair.second){
        cout << "( " << nbr.first << ", " << nbr.second << " )";
        cout << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g;
  g.addEdge(0,1,1,2);
  g.addEdge(1,2,1,5);
  g.addEdge(1,3,1,3);
  g.addEdge(2,3,1,4);
  g.print();
  return 0;
}