
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <climits>

using namespace std;

 
namespace ariel
{
  
 

	
 
    int Algorithms::isConnected (Graph graph)
        {
        

    bool isDirected = graph.isDirectedGraph ();	  
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
							   
 
 
    void Algorithms::dfs(Graph graph, vector<bool>& visited, size_t node) 
    {
        visited[node] = true;
        std::vector<int> neighbors = graph.getNeighbors(node); // Get the neighbors of the current node.
        for (int neighbor : neighbors) 
        {
            if (!visited[((size_t)neighbor)]) 
            { // If the neighbor is not visited, do dfs on it.
                dfs(graph, visited, ((size_t)neighbor));
            }
        }
    }
								
 
    string Algorithms::  shortestPath (Graph graph,size_t src,size_t dest)
            {
                    // check for valid source and destination vertices
                    if (src >= graph.getSize() || dest >= graph.getSize()) 
                    {
                        return "Invalid source or destination vertex.";
                    }

                    //if src and dest are the same vertex
                    if (src == dest) 
                    {
                        return to_string(src);
                    }
                    /*
                    if the graph is weighted  with positive weight use Dijkstra algorithm
                    if the graph is weighted with negative weight use Bellman-Ford algorithm
                    if the graph is not weighted use BFS algorithm 

                    */

                    if (graph.isWeightedGraph()) 
                    {
                        if (graph.isNegativeWeightedGraph()) 
                        {
                            return bellmanFord(graph, src, dest); // Bellman-Ford algorithm
                        } else 
                        {
                            return dijkstra(graph, src, dest); // Dijkstra algorithm
                        }
                    } else
                     {
                        return bfs(graph, src, dest); // BFS algorithm
                    }
                    



            return "1";
            // Implementation goes here
            }

     string Algorithms:: bfs(Graph& graph, size_t src, size_t dest) {
        size_t numVertices = graph.getSize();
        std::vector<bool> color(numVertices, 0); // 0 - white, 1 - gray, 2 - black
        std::vector<int> parent(numVertices, -1); // Vector to keep track of the parent of each vertex in the BFS traversal
        std::vector<int> distance(numVertices, -1); // Vector to keep track of the distance of each vertex from the source vertex
        std::vector<int> path; // Vector to store the path from the source vertex to the destination vertex
        std::queue<int> q; // Queue for BFS traversal
        
        q.push(src); // Push the source vertex to the queue
        color[src] = 1; // Color the source vertex as gray
        distance[src] = 0; // Distance of the source vertex from itself is 0
        parent[src] = -1; // Parent of the source vertex is -1

        while (!q.empty()){
            size_t currVertex = (size_t)q.front(); // Get the front vertex from the queue
            q.pop(); // Pop the front vertex from the queue

            std::vector<int> neighbors = graph.getNeighbors(currVertex); // Get the neighbors of the current vertex
            for (int neighbor : neighbors)
            {
                if (color[(size_t)neighbor] == 0){
                     // If the neighbor is white, color it as gray and push it to the queue
                    color[(size_t)neighbor] = 1; // Color the neighbor as gray
                    distance[(size_t)neighbor] = distance[(size_t)currVertex] + 1; // Distance of the neighbor from the source vertex is distance of the current vertex + 1
                    parent[(size_t)neighbor] = currVertex; // Parent of the neighbor is the current vertex
                    q.push(neighbor); // Push the neighbor to the queue
                }
            }
            color[(size_t)currVertex] = 2; // Color the current vertex as black


        }
        // If the destination vertex is not reachable from the source vertex, return "No path exists between the source and destination vertices."
        if (distance[dest] == -1) {
            return "No path exists between the source and destination vertices.";
        }
        //print the path
        
        int currVertex = dest;
        while (currVertex != -1) {
            path.push_back(currVertex);
            currVertex = parent[(size_t)currVertex];
        }   
        std::reverse(path.begin(), path.end());
        string result = "The shortest path from " + std::to_string(src) + " to " + std::to_string(dest) + " is: ";
        for (size_t i = 0; i < path.size(); i++) 
        {
            result += std::to_string(path[i]);
            if (i != path.size() - 1) 
            {
                result += " -> ";
            }
        }
        return result;


     }  

     string Algorithms:: bellmanFord(Graph& graph, size_t src, size_t dest) {
        
        size_t numVertices = graph.getSize();
        std::vector<int> distance(numVertices, INT_MAX); // Vector to keep track of the distance of each vertex from the source vertex
        std::vector<int> parent(numVertices, -1); // Vector to keep track of the parent of each vertex in the shortest path

        distance[src] = 0; 

        // Relax all edges V-1 times
        for (size_t i = 0; i < numVertices - 1; i++) { // V-1 iterations
            for (size_t u = 0; u < numVertices; u++) {
                std::vector<int> neighbors = graph.getNeighbors(u); // Get the neighbors of vertex u
                for (int v : neighbors) {
                    if (distance[(size_t)u] != INT_MAX && distance[(size_t)u] + graph.getWeight(u, v) < distance[(size_t)v]) {
                        distance[(size_t)v] = distance[(size_t)u] + graph.getWeight(u, v);
                        parent[(size_t)v] = u;
                    }
                }
            }
        }

        // Check for negative cycles

        for (size_t u = 0; u < numVertices; u++) {
            std::vector<int> neighbors = graph.getNeighbors(u); // Get the neighbors of vertex u
            for (int v : neighbors) {
                if (distance[u] != INT_MAX && distance[u] + graph.getWeight(u, v) < distance[v]) {
                    return "Negative cycle exists in the graph.";
                }
            }
        }

        //print the path
        std::vector<int> path;
        int currVertex = dest;
        while (currVertex != -1) {
            path.push_back(currVertex);
            currVertex = parent[(size_t)currVertex];
        }

        std::reverse(path.begin(), path.end());
        string result = "The shortest path from " + std::to_string(src) + " to " + std::to_string(dest) + " is: ";

        for (size_t i = 0; i < path.size(); i++) {
            result += std::to_string(path[i]);
            if (i != path.size() - 1) {
                result += " -> ";
            }
        }

     }


    string Algorithms:: dijkstra(Graph graph, size_t src, size_t dest) {
        return "1";
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
