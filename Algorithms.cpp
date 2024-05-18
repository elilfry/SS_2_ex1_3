
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
							   
 
 
    void Algorithms::dfs(Graph &graph, vector<bool>& visited, size_t node) 
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
								
 
    string Algorithms::  shortestPath (Graph& graph,size_t src,size_t dest)
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
            return "No path exists between the source and destination vertices";
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
                result += "->";
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
                    int weight = graph.getWeight(u, (size_t)v);
                    if (distance[u] != INT_MAX && distance[u] + weight< distance[(size_t)v]) {
                        distance[(size_t)v] = distance[u] + weight; //relax the edge
                        parent[(size_t)v] = u;
                    }
                }
            }
        }

        // Check for negative cycles

        for (size_t u = 0; u < numVertices; u++) {
            std::vector<int> neighbors = graph.getNeighbors(u); // Get the neighbors of vertex u
            for (int v : neighbors) {
                if (distance[u] != INT_MAX && distance[u] + graph.getWeight(u, (size_t)v) < distance[(size_t)v]) {
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
                result += "->";
            }
        }
        return result;

     }


    string Algorithms:: dijkstra(Graph& graph, size_t src, size_t dest) {
        size_t numVertices = graph.getSize();
        std::vector<int> distance(numVertices, INT_MAX); // Vector to keep track of the distance of each vertex from the source vertex
        std::vector<int> parent(numVertices, -1); // Vector to keep track of the parent of each vertex in the shortest path
        std::vector<bool> visited(numVertices, false); // Vector to keep track of the visited vertices

        distance[src] = 0; // Distance of the source vertex from itself is 0

        // Create a priority queue to store vertices that are being preprocessed
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, src}); // Push the source vertex to the priority queue

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with the minimum distance from the priority queue
            pq.pop(); // Pop the vertex from the priority queue

            if (visited[(size_t)u]) {
                continue; // If the vertex is already visited, skip it
            }

            visited[(size_t)u] = true; // Mark the vertex as visited

            std::vector<int> neighbors = graph.getNeighbors((size_t)u); // Get the neighbors of the current vertex
            for (int v : neighbors) {
                int weight = graph.getWeight((size_t)u, (size_t)v);
                if (distance[(size_t)u] != INT_MAX && distance[(size_t)u] + weight < distance[(size_t)v]) {
                    distance[(size_t)v] = distance[(size_t)u] + weight; // Update the distance of the neighbor if a shorter path is found
                    parent[(size_t)v] = u; // Update the parent of the neighbor
                    pq.push({distance[(size_t)v], v}); // Push the neighbor to the priority queue
                }
            }
        }

        // If the destination vertex is not reachable 
        if (distance[(size_t)dest] == INT_MAX) {
            return "No path exists between the source and destination vertices";
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
                result += "->";
            }
        }
        return result;


            }


    bool Algorithms::isCycleDirected(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack,std::vector<int>& path) {
        if (!visited[node]) {
            visited[node] = true;
            recStack[node] = true;
            path.push_back(node);
            

            std::vector<int> neighbors = graph.getNeighbors(node);
            for (int neighbor : neighbors) {
                if (!visited[(size_t)neighbor] && isCycleDirected(graph, (size_t)neighbor, visited, recStack, path)) {
                    return true;
                } else if (recStack[(size_t)neighbor]) {
                    path.push_back(neighbor);
                    return true;
                }
            }
        }
        recStack[node] = false;
        path.pop_back();
        return false;
    }


    bool Algorithms::isCycleUndirected(Graph& graph, size_t node, int parent, std::vector<bool>& visited, std::vector<int>& path) {
        visited[node] = true;
        path.push_back(node);

        std::vector<int> neighbors = graph.getNeighbors(node);
        for (int neighbor : neighbors) {
            if (!visited[(size_t)neighbor]) {
                if (isCycleUndirected(graph, (size_t)neighbor, node, visited, path)) {
                    return true;
                }
            } else if (neighbor != parent) {
                path.push_back(neighbor);
                return true;
            }
        }
        path.pop_back();
        return false;
    }

    string Algorithms::isContainsCycle(Graph& graph) {
    size_t numVertices = graph.getSize();
    std::vector<bool> visited(numVertices, false);
    std::vector<bool> recStack(numVertices, false);
    std::vector<int> cyclePath;

    if (graph.isDirectedGraph()) {
        for (size_t i = 0; i < numVertices; i++) {
            if (isCycleDirected(graph, i, visited, recStack, cyclePath)) {
                if (!cyclePath.empty()) {
                    std::reverse(cyclePath.begin(), cyclePath.end());
                    string result = "The cycle is: ";
                    for (size_t j = 0; j < cyclePath.size(); j++) {
                        result += std::to_string(cyclePath[j]);
                        if (j != cyclePath.size() - 1) {
                            result += "->";
                        }
                    }
                    return result;
                }
            }
        }
    } else {
        for (size_t i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                cyclePath.clear();
                if (isCycleUndirected(graph, i, -1, visited, cyclePath)) {
                    if (!cyclePath.empty()) {
                        string result = "The cycle is: ";
                        for (size_t j = 0; j < cyclePath.size(); j++) {
                            result += std::to_string(cyclePath[j]);
                            if (j != cyclePath.size() - 1) {
                                result += "->";
                            }
                        }
                        return result;
                    }
                }
            }
        }
    }

    return "The graph does not contain a cycle";
}


    
    // string Algorithms::isContainsCycle (Graph graph)
    //         {
    //         size_t numVertices = graph.getSize();
    //         std::vector<bool> visited(numVertices, false); // Vector to keep track of the visited vertices
    //         std::vector<bool> recStack(numVertices, false); // Vector to keep track of the vertices in the recursion stack

    //         std::vector<int> cyclePath;

    //         if(graph.isDirectedGraph()) 
    //         { 
    //             for (size_t i = 0; i < numVertices; i++) 
    //             {
    //                 if(isCycleDirected(graph, i, visited, recStack, cyclePath)) 
    //                 {

    //                     //print the cycle
    //                     int currVertex = i;
    //                     while (!recStack[(size_t)currVertex]) 
    //                     {
    //                         currVertex = graph.getNeighbors((size_t)currVertex)[0];
    //                     }
    //                     int startVertex = currVertex;
    //                     do 
    //                     {
    //                         cyclePath.push_back(currVertex);
    //                         currVertex = graph.getNeighbors((size_t)currVertex)[0];
    //                     } while (currVertex != startVertex);
    //                     cyclePath.push_back(startVertex);

    //                     string result = "The cycle is: ";
    //                     for (size_t i = 0; i < cyclePath.size(); i++) 
    //                     {
    //                         result += std::to_string(cyclePath[i]);
    //                         if (i != cyclePath.size() - 1) 
    //                         {
    //                             result += " -> ";
    //                         }
    //                     }
    //                     return result;


                        
    //                 }
    //         }
    //         }
    //         else 
    //         {
    //             for (size_t i = 0; i < numVertices; i++) 
    //             {
    //                 if(isCycleUndirected(graph, i, -1, visited)) 
    //                 {
    //                   //print the cycle
    //                     int currVertex = i;
    //                     int parent = -1;
    //                     do 
    //                     {
    //                         cyclePath.push_back(currVertex);
    //                         std::vector<int> neighbors = graph.getNeighbors((size_t)currVertex);
    //                         for (int neighbor : neighbors) 
    //                         {
    //                             if (neighbor != parent && visited[(size_t)neighbor]) 
    //                             {
    //                                 cyclePath.push_back(neighbor);
    //                                 return "The cycle is: ";
    //                             }
    //                         }
    //                         parent = currVertex;
    //                         currVertex = graph.getNeighbors((size_t)currVertex)[0];
    //                     } while (currVertex != i);
    //                     cyclePath.push_back(i);

    //                     string result = "The cycle is: ";
    //                     for (size_t i = 0; i < cyclePath.size(); i++) 
    //                     {
    //                         result += std::to_string(cyclePath[i]);
    //                         if (i != cyclePath.size() - 1) 
    //                         {
    //                             result += " -> ";
    //                         }
    //                     }
    //                     return result;

    //                 }
    //             }
    //         } 
    //         return "The graph not contain a cycle"; // The graph does not contain a cycle
    //         }
            
 
	
        
    //this fucntion check if the graph is bipartite.
    // If the graph is bipartite, then the fucntion will return the two groups, else return 0.

    string Algorithms::isBipartite(Graph& graph)
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
                                return "The graph is  not bipartite";
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



        
    
    string Algorithms::negativeCycle (Graph& graph)
    {
    size_t numVertices = graph.getSize();
    if(numVertices == 0)
    {
        return "No negative cycle -the graph have no vertex.";
    }

    size_t numEdges = graph.getNumberOfEdges();
    if(numEdges == 0)
    {
        return "No negative cycle -the graph have no edge.";
    }

    if(!graph.isNegativeWeightedGraph())
    {
        return "No negative cycle -the graph have no negative weight.";
    }


    std::vector<int> distance(numVertices, 0); // Vector to keep track of the distance of each vertex from the source vertex

    // Relax all edges V-1 times
    for (size_t i = 0; i < numVertices - 1; i++) { // V-1 iterations
        for (size_t u = 0; u < numVertices; u++) {
            std::vector<int> neighbors = graph.getNeighbors(u); // Get the neighbors of vertex u
            for (int v : neighbors) {
                int weight = graph.getWeight(u, (size_t)v);
                if (distance[u] + weight < distance[(size_t)v]) {
                    distance[(size_t)v] = distance[u] + weight; //relax the edge
                }
            }
        }

    } 
    // Check for negative cycles
    for (size_t u = 0; u < numVertices; u++) {
        std::vector<int> neighbors = graph.getNeighbors(u); // Get the neighbors of vertex u
        for (int v : neighbors) {
            if (distance[u] + graph.getWeight(u, (size_t)v) < distance[(size_t)v]) {
                return "Negative cycle exists in the graph.";
            }
        }
    }
    return "No negative cycle.";
    }

 
 
} 
