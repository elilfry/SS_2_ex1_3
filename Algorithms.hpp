#pragma once
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP


#include "Graph.hpp"
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <stack>
#include <algorithm>
#include <limits>



using std::string;



namespace ariel {

    class Algorithms {
        public:

/*
the function check if the graph is connected
1 if the graph is connected
0 if the graph is not connected

*/
 static  int isConnected(Graph graph);

static void dfs(Graph& graph, std::vector<bool>& visited, size_t node) ;


static bool isCycleUndirected(Graph& graph, size_t node, int parent, std::vector<bool>& visited , std::vector<int>& path) ;

static bool isCycleDirected(Graph& graph, size_t node, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<int>& path) ;

/*
the function return the light path between two  vertex 
if the graph is not weighted the function return the shortest path
if the graph is weighted the function return the light path
if there is no path between the two vertex the function return -1
*/

/*
the function return a cycle in the graph,if there is no cycle the function return 0
*/
 static string isContainsCycle(Graph& graph);

 static string shortestPath(Graph& graph, size_t start, size_t end);

/*
the function return the shortest path between two vertex using bfs algorithm

*/
static string  bfs(Graph& graph, size_t src, size_t dest);


static string  bellmanFord(Graph&  graph, size_t src, size_t dest);



static string  dijkstra(Graph& graph, size_t src, size_t dest);



/*
This fucntion check if the graph is bipartite.
    If the graph is bipartite, then the fucntion will return the two groups, else return 0.

 @param graph - the graph to check if it is bipartite
 
*/
static string isBipartite(Graph& graph);

/*
 This function checks if a negative cycle exists in the graph.
    If a negative cycle exists, the function will return 1, else return "no negative cycle".

*/
 static string negativeCycle(Graph& graph);

    };
}

#endif 

