
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
	  
 if (isDirected) { // Directed graph do dfs and check if all the vertices are visited
        dfs(graph, visited, 0);
        for (bool v : visited) {
            if (!v) { // If there is a vertex that is not visited, the graph is not connected.
                return 0; // The graph is not connected.
            }
        }
        return 1; // The graph is connected.
    } else { // Undirected graph do dfs for each vertex and check if all the vertices are visited
        for (size_t i = 0; i < numVertices; i++) {
            visited.assign(numVertices, false); // Reset the visited vector.
            dfs(graph, visited, i);
            for (bool v : visited) {
                if (!v) {
                    return 0; // The graph is not connected.
                }
            }
        }
        return 1; // The graph is connected.
    }
}
							   
 
 
 void Algorithms::dfs(Graph graph, vector<bool>& visited, size_t node) {
    visited[node] = true;
    std::vector<int> neighbors = graph.getNeighbors(node); // Get the neighbors of the current node.
    for (int neighbor : neighbors) {
        if (!visited[((size_t)neighbor)]) { // If the neighbor is not visited, do dfs on it.
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
 
	
        
//this fucntion check if the graph is bipartite.
   // If the graph is bipartite, then the fucntion will return the two groups, else return 0.

 string Algorithms::isBipartite(Graph graph)
        {
            size_t numVertices = graph.getSize();
            std::vector<int> color(numVertices, -1); // -1 represents uncolored, 0 represents color 1, 1 represents color 2
            std::vector<int> group1, group2;

            for (size_t i = 0; i < numVertices; i++)
            {
                if (color[i] == -1) // If the current vertex is uncolored, start BFS from it
                {
                    std::queue<int> q; // Queue for BFS
                    q.push(i); // Push the current vertex to the queue
                    color[i] = 0; // Color the current vertex with color 1
                    group1.push_back(i); // Add the current vertex to group 1

                    while (!q.empty())
                    {
                        int currVertex = q.front(); // Get the front vertex from the queue
                        q.pop(); // Pop the front vertex from the queue

                        std::vector<int> neighbors = graph.getNeighbors((size_t)currVertex); // Get the neighbors of the current vertex
                        for (int neighbor : neighbors)
                        {
                            if (color[(size_t)neighbor] == -1) // If the neighbor is uncolored, color it with the opposite color of the current vertex
                            {
                                color[(size_t)neighbor] = 1 - color[(size_t)currVertex]; // Color the neighbor with the opposite color of the current vertex
                                q.push(neighbor);

                                if (color[(size_t)neighbor] == 0) // If the neighbor is colored with color 1, add it to group 1
                                {
                                    group1.push_back(neighbor);
                                }
                                else // If the neighbor is colored with color 2, add it to group 2
                                {
                                    group2.push_back(neighbor);
                                }
                            }
                            else if (color[(size_t)neighbor] == color[(size_t)currVertex]) // If the neighbor has the same color as the current vertex, the graph is not bipartite
                            {
                               return "The graph is  not bipartite\n";
                            }
                        }
                    }
                }
            }
            
            //print the 2 groups
            string result = "The graph is bipartite: A={";
            for (size_t i = 0; i < group1.size(); i++)
            {
                result += std::to_string(group1[i]);
                if (i != group1.size() - 1)
                {
                    result += ", ";
                }
            }

            result += "}, B={";
            for (size_t i = 0; i < group2.size(); i++)
            {
                result += std::to_string(group2[i]);
                if (i != group2.size() - 1)
                {
                    result += ", ";
                }
            }

            result += "}";
            return result;
            
       
        }



	
 
 int Algorithms::negativeCycle (Graph graph)
	{
	return 1;

} 
 

 
 
} 
