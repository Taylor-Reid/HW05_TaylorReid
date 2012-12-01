#include "ListGraph.h"

ListGraph::ListGraph(int numNodes){

}
ListGraph::~ListGraph(){

}
/*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
   void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
		EList::const_iterator it;
		NWPair check;
		if(u>=0 && u < edgeList.size() && v>=0 && v < edgeList.size() && u!=v){
			for(it = edgeList[u].begin(); it != edgeList[u].end();it++){
				check =*it;
				if(check.first == v ){//if an edge already exists, we do nothing and exit
					return;
				}
			}//if the for loop found no edge, we make one
			if(weight>0){
				edgeList[u].push_back(NWPair(v,weight));
				edgeList[v].push_back(NWPair(u,weight));
				num_edges++;
			}
		}
  }
  

  /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
		EList::const_iterator it;
		NWPair check;
		if(u>=0 && u < edgeList.size() && v>=0 && v < edgeList.size() && u!=v){
			for(it = edgeList[u].begin(); it != edgeList[u].end();it++){
				check = *it;
				if(check.first == v ){
					return check.second;
				}
			}
			
		}
	  return EdgeWeight(0);
  }

  /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
  std::list<NWPair> ListGraph::getAdj(NodeID u) const {  
	  return edgeList[u];
  }

  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
  unsigned ListGraph::degree(NodeID u) const {
	  return edgeList[u].size();
	  //not sure this is right, need to check...

  }

  /*
   * Return the number of nodes in the graph.
   */
  unsigned ListGraph::size() const {
	  return edgeList.size();
  }

  /* 
   * Return the number of edges in the graph.
   */
  unsigned ListGraph::numEdges() const{
	  return num_edges;
  }