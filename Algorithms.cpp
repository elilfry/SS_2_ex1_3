
#include "Algorithms.hpp"
#include "Graph.hpp"
  
using namespace std;

 
namespace ariel
{
  
 

	
 
 int Algorithms::isConnected (Graph graph)
	{
	  

bool isDirected = graph.isDirectedGraph (graph);	  
size_t numVertices = graph.getSize ();
std::vector < bool >visited (numVertices, false);
	  
 if (isDirected) {
        dfs(graph, visited, 0);
        for (bool v : visited) {
            if (!v) {
                return 0;
            }
        }
        return 1;
    } else {
        for (size_t i = 0; i < numVertices; i++) {
            visited.assign(numVertices, false);
            dfs(graph, visited, i);
            for (bool v : visited) {
                if (!v) {
                    return 0;
                }
            }
        }
        return 1;
    }
}
							   
 
 
 void Algorithms::dfs(Graph graph, vector<bool>& visited, size_t node) {
    visited[node] = true;
    std::vector<int> neighbors = graph.getNeighbors(node);
    for (int neighbor : neighbors) {
        if (!visited[((size_t)neighbor)]) {
            dfs(graph, visited, ((size_t)neighbor));
        }
    }
}
								
 
 int Algorithms::shortestPath (Graph graph,size_t start,size_t end)
								{
								return 1;
								// Implementation goes here
								} 
 
 int Algorithms::isContainsCycle (Graph graph)
								{
																return 1;

								// Implementation goes here
								} 
 int Algorithms::isBipartiteGraph (Graph graph)
	{
	return 1;	
    } 
 
 int Algorithms::negativeCycle (Graph graph)
	{
	return 1;

} 
 

 
 
} 
