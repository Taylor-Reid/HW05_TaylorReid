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
	  //don't forget to num_edges++;
  }
  

  /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	  return 0.0;
  }

  /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
  std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	  std::list<NWPair> aList;
	  
	  return aList;
  }

  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
  unsigned ListGraph::degree(NodeID u) const {
	  
  }

  /*
   * Return the number of nodes in the graph.
   */
  unsigned ListGraph::size() const {
	  return 0.0;
  }

  /* 
   * Return the number of edges in the graph.
   */
  unsigned ListGraph::numEdges() const{
	  return num_edges;
  }