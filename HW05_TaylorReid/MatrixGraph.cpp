#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(unsigned num_nodes) {
	M.resize(num_nodes);
	for(int i = 0; i <num_nodes; i++){
		M[i].resize(num_nodes);
	}
}
MatrixGraph::~MatrixGraph(){

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
   void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	  if(u>=0 && u < M.size() && v>=0 && v < M.size() && u!=v && M[u][v]==0 && weight>0){
		  M[u][v]=weight;
		  M[v][u]=weight;
	  }
  }
  

  /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
   */
  EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	  if(u>=0 && u < M.size() && v>=0 && v < M.size()){
		return M[u][v];
	  }
	  return 0.0;
  }

  /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
   *
   * Preconditions: u is a legal label.
   */
  std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	  std::list<NWPair> aList;
	  int counter = 0;
	  for(int i = 0; i<M[u].size() ; i++){
		  if(M[u][i] != 0){
			  aList.push_front(NWPair(u,M[u][i]));
		  }
	  }
	  return aList;
  }

  /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
  unsigned MatrixGraph::degree(NodeID u) const {
	  int counter = 0;
	  for(int i = 0; i<M[u].size() ; i++){
		  if(M[u][i] != 0){
			  counter++;
		  }
	  }
	  return counter;
  }

  /*
   * Return the number of nodes in the graph.
   */
  unsigned MatrixGraph::size() const {
	  return 0.0;
  }

  /* 
   * Return the number of edges in the graph.
   */
  unsigned MatrixGraph::numEdges() const{
	  return 0.0;
  }