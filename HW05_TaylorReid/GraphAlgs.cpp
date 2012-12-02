#include "GraphAlgs.h"


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){

	//not sure if i'll be using this set
	std::vector<NodeID> nodes;
	nodes.resize(G->size());
	EdgeWeight dist = 0;
	///////////
	
	bestDist=0;
	for(int i = 0 ; i < G->size()-1 ; i++){
		bestDist+= G->weight(i,i+1);
	}
	bestDist+=G->weight(G->size()-1,0);


	return std::pair<std::vector<NodeID>, EdgeWeight>(nodes, dist);
}



void FindBestTour(Graph* G, std::vector<NodeID> route, NodeID n, NodeID start){
	if(n-start == 1){
		EdgeWeight thisDist=0;
		for(int i = 0 ; i < route.size()-1 ; i++){
			thisDist+= G->weight(i,i+1);
		}
		thisDist+= G->weight(route.size()-1,0);
		if(thisDist < bestDist){
			bestDist=thisDist;
			bestRoute=route;
		}
	}else{

	}
}