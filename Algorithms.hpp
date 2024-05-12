#pragma once
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP


#include "Graph.hpp"
#include <vector>


namespace ariel {

    class Algorithms {
        public:

/*
the function check if the graph is connected
1 if the graph is connected
0 if the graph is not connected

*/
 static  int isConnected(Graph graph);

static void dfs(Graph graph, std::vector<bool>& visited, size_t node) ;


/*
the function return the light path between two  vertex 
if the graph is not weighted the function return the shortest path
if the graph is weighted the function return the light path
if there is no path between the two vertex the function return -1
*/
/*
the function return a cycle in the graph,if there is no cycle the function return 0

*/
 int isContainsCycle(Graph graph);

 int shortestPath(Graph graph, size_t start, size_t end);

/*
This fucntion check if the graph is bipartite.
    If the graph is bipartite, then the fucntion will return the two groups, else return 0.

 @param graph - the graph to check if it is bipartite
 
*/
static int isBipartite(Graph graph);

/*
 This function checks if a negative cycle exists in the graph.
    If a negative cycle exists, the function will return 1, else return "no negative cycle".

*/
 int negativeCycle(Graph graph);

    };
}
#endif // ALGORITHMS_HPP
