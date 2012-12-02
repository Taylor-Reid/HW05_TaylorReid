#include "GraphAlgs.h"


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){

	bestDist=0;
	bestRoute.resize(G->size());
	//set the best route and best distance to those of going to the nodes in NodeID order
	for(int i = 0 ; i < G->size()-1 ; i++){
		bestDist+= G->weight(i,i+1);
		bestRoute[i]=i;
	}
	//set the last ones not covered in the loop (it doesn't loop from the last back to the first)
	bestDist+=G->weight(G->size()-1,0);
	bestRoute[G->size()-1]=G->size()-1;

	FindBestTour(G,bestRoute,G->size(),0,0);

	return std::pair<std::vector<NodeID>, EdgeWeight>(bestRoute, bestDist);
}



void FindBestTour(Graph* G, std::vector<NodeID> route, int n, NodeID start, EdgeWeight thisDist){
	if(n-start == 1){
		thisDist+= G->weight(route.size()-1,0);
		if(thisDist < bestDist){
			bestDist=thisDist;
			bestRoute=route;
		}
	}else{
		if(thisDist > bestDist){
			return;
		}
		for(int i = 0; i < n; i++){
			swap(route,start,i);
			// recurses passing a start position one further along
			// and passes the (previous dist + dist to the next node)
			FindBestTour(G,route,n,start+1,thisDist+G->weight(start,start+1));
			swap(route,start,i);
		}
	}
}

void swap(std::vector<NodeID> route, int u, int v){
	NodeID temp = route[u];
	route[u]=route[v];
	route[v]=temp;
}