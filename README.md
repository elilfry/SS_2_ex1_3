# System Programming 2 - assignment 1
Eli Frydman
# Graph Algorithms Task

This is a C++ library for performing various graph algorithms. It provides functionality for checking graph properties, finding shortest paths, detecting cycles, and more. The library is composed of two main components: `Algorithms` and `Graph`.


## Features

- **Graph Connectivity:** 
  - Check if a graph is connected. This determines whether there is a path between every pair of vertices in the graph.

- **Cycle Detection:** 
  - Identify if there are cycles in both directed and undirected graphs.

- **Shortest Path:** 
  - Calculate the shortest or lightest path between two vertices using various algorithms:
    - **BFS (Breadth-First Search):** Ideal for unweighted graphs to find the shortest path.
    - **Dijkstra's Algorithm:** Suitable for graphs with non-negative weights to find the shortest path.
    - **Bellman-Ford Algorithm:** Handles graphs with negative weights and can detect negative weight cycles.

- **is bipartite** 
  - Determine if a graph is bipartite, meaning its vertices can be divided into two disjoint sets such that no two graph vertices within the same set are adjacent.
- **negativeCycle**
  - Check for negative cycles in the graph, which are cycles whose total weight is negative.
 

## Files

### 1. Algorithms.cpp

This file contains the implementation of various graph algorithms.

#### Functions

- `static int isConnected(Graph graph);`
  - Checks if the graph is connected.
  - Returns 1 if connected, 0 if not.

- `static void dfs(Graph& graph, std::vector<bool>& visited, size_t node);`
  - Depth-First Search utility function.

- `static bool isCycleUndirected(Graph& graph, size_t node, int parent, std::vector<bool>& visited, std::vector<int>& path);`
  - Checks for cycles in an undirected graph.

- `static bool isCycleDirected(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& path);`
  - Checks for cycles in a directed graph.

- `static string isContainsCycle(Graph& graph);`
  - Returns a cycle in the graph if one exists, otherwise returns 0.

- `static string shortestPath(Graph& graph, size_t start, size_t end);`
  - Returns the shortest or lightest path between two vertices.

- `static string bfs(Graph& graph, size_t src, size_t dest);`
  - Uses BFS algorithm to find the shortest path.

- `static string bellmanFord(Graph& graph, size_t src, size_t dest);`
  - Uses Bellman-Ford algorithm to find the shortest path.

- `static string dijkstra(Graph& graph, size_t src, size_t dest);`
  - Uses Dijkstra's algorithm to find the shortest path.

- `static string isBipartite(Graph& graph);`
  - Checks if the graph is bipartite and returns the two groups if true, otherwise returns 0.

- `static string negativeCycle(Graph& graph);`
  - Checks for the existence of a negative cycle in the graph and returns the result.

### 2. Graph.cpp

This file contains the implementation of the `Graph` class, which represents a graph using an adjacency matrix.

#### Functions

- `void loadGraph(const std::vector<std::vector<int>>& graph);`
  - Loads a graph from an adjacency matrix, ensuring it is a valid square matrix without self-loops.

- `void printGraph();`
  - Prints the graph's adjacency matrix.

- `bool isWeightedGraph();`
  - Checks if the graph is weighted.

- `bool isDirectedGraph();`
  - Checks if the graph is directed.

- `size_t getNumberOfEdges();`
  - Returns the number of edges in the graph.

- `std::vector<int> getNeighbors(size_t vertex);`
  - Returns the neighbors of a given vertex.

- `size_t getSize();`
  - Returns the size of the graph.

- `bool isNegativeWeightedGraph();`
  - Checks if the graph has negative weights.

- `int getWeight(size_t src, size_t dest);`
  - Returns the weight of the edge between two vertices.

- `size_t getNumberOfVertices();`
  - Returns the number of vertices in the graph.

/////////////////////////////////////////////

### Algorithms.cpp

#### Function: `int Algorithms::isConnected(Graph graph)`
**Description:** Checks if the graph is connected.
**Parameters:**
- `graph`: A `Graph` object.

#### Function: `void Algorithms::dfs(Graph& graph, std::vector<bool>& visited, size_t node)`
**Description:** Performs a depth-first search on the graph.
**Parameters:**
- `graph`: A `Graph` object.
- `visited`: A vector indicating which vertices have been visited during the traversal.
- `node`: The starting vertex for the DFS traversal.

#### Function: `bool Algorithms::isCycleUndirected(Graph& graph, size_t node, int parent, std::vector<bool>& visited, std::vector<int>& path)`
**Description:** Checks for cycles in an undirected graph.
**Parameters:**
- `graph`: A `Graph` object.
- `node`: Current node.
- `parent`: Parent node.
- `visited`: A vector indicating which vertices have been visited during the traversal.
- `path`: A vector storing the current path for cycle detection.

#### Function: `bool Algorithms::isCycleDirected(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& path)`
**Description:** Checks for cycles in a directed graph.
**Parameters:**
- `graph`: A `Graph` object.
- `node`: Current node.
- `visited`: A vector indicating which vertices have been visited during the traversal.
- `recStack`: A recursion stack to keep track of the nodes currently in the recursion stack.
- `path`: A vector storing the current path for cycle detection.

#### Function: `string Algorithms::isContainsCycle(Graph& graph)`
**Description:** Determines if the graph contains a cycle and returns the cycle path if one exists.
**Parameters:**
- `graph`: A `Graph` object.

#### Function: `string Algorithms::shortestPath(Graph& graph, size_t start, size_t end)`
**Description:** Finds the shortest path between two vertices using the appropriate algorithm.
**Parameters:**
- `graph`: A `Graph` object.
- `start`: Start vertex index.
- `end`: End vertex index.

#### Function: `string Algorithms::bfs(Graph& graph, size_t src, size_t dest)`
**Description:** Uses BFS to find the shortest path in an unweighted graph.
**Parameters:**
- `graph`: A `Graph` object.
- `src`: Source vertex index.
- `dest`: Destination vertex index.

#### Function: `string Algorithms::bellmanFord(Graph& graph, size_t src, size_t dest)`
**Description:** Uses Bellman-Ford to find the shortest path in a graph with negative weights.
**Parameters:**
- `graph`: A `Graph` object.
- `src`: Source vertex index.
- `dest`: Destination vertex index.

#### Function: `string Algorithms::dijkstra(Graph& graph, size_t src, size_t dest)`
**Description:** Uses Dijkstra's algorithm to find the shortest path in a graph with non-negative weights.
**Parameters:**
- `graph`: A `Graph` object.
- `src`: Source vertex index.
- `dest`: Destination vertex index.

#### Function: `string Algorithms::isBipartite(Graph& graph)`
**Description:** Checks if the graph is bipartite.
**Parameters:**
- `graph`: A `Graph` object.

#### Function: `string Algorithms::negativeCycle(Graph& graph)`
**Description:** Checks for the existence of a negative cycle in the graph.
**Parameters:**
- `graph`: A `Graph` object.

### Graph.cpp

#### Function: `void Graph::loadGraph(const std::vector<std::vector<int>>& graph)`
**Description:** Loads the graph from the given adjacency matrix, ensuring it is valid.
**Parameters:**
- `graph`: A square matrix representing the graph.

#### Function: `void Graph::printGraph()`
**Description:** Prints the adjacency matrix of the graph.
**Parameters:** None.

#### Function: `bool Graph::isWeightedGraph()`
**Description:** Checks if the graph contains weights other than 0 and 1.
**Parameters:** None.

#### Function: `bool Graph::isDirectedGraph()`
**Description:** Checks if the graph is directed by verifying if the adjacency matrix is symmetric.
**Parameters:** None.

#### Function: `size_t Graph::getNumberOfEdges()`
**Description:** Counts the number of edges in the graph, taking into account if the graph is directed or undirected.
**Parameters:** None.

#### Function: `std::vector<int> Graph::getNeighbors(size_t vertex)`
**Description:** Returns a list of vertices adjacent to the given vertex.
**Parameters:**
- `vertex`: A vertex index.

#### Function: `size_t Graph::getSize()`
**Description:** Returns the number of vertices in the graph.
**Parameters:** None.

#### Function: `bool Graph::isNegativeWeightedGraph()`
**Description:** Checks if the graph contains any negative edge weights.
**Parameters:** None.

#### Function: `int Graph::getWeight(size_t src, size_t dest)`
**Description:** Returns the weight of the edge from `src` to `dest`.
**Parameters:**
- `src`: Source vertex index.
- `dest`: Destination vertex index.

#### Function: `size_t Graph::getNumberOfVertices()`
**Description:** Returns the number of vertices in the graph.
**Parameters:*

