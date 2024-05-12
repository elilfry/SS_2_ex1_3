#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;

namespace ariel {

    



    void  Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

        // Check if the graph is a square matrix.
        
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[i].size() != graph.size()) {
                throw ("The graph is not a square matrix.");
            }
        }

        // Check if the graph is empty.
        if (graph.size() == 0) {
            throw ("The graph is empty.");
        }

        // Check if the graph has a self loop
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[i][i] != 0) {
                throw ("The graph has a self loop.");
            }
        }

        adjMatrix = graph;


        
    }

    void  Graph:: printGraph()  {
        size_t numVertices = adjMatrix.size();

        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }



/*
this function check if the graph is connected
*/
bool Graph::isWeightedGraph(const Graph g){

    size_t size = g.adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if ( g.adjMatrix[i][j] != 1 && g.adjMatrix[i][j] != 0) { 
                return true;
            }
        }
    }
    return false;
}

/*
this function check if the graph is directed
if the graph is syimetric the graph is not directed -false
if the graph is  not syimetric the graph is directed - true
*/
bool Graph::isDirectedGraph(const Graph g){ 
    size_t size = g.adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (g.adjMatrix[i][j] != g.adjMatrix[j][i]) { 
                return true;
            }
        }
    }
    return false;
}

//get neighbors of a vertex

std::vector<int> Graph::getNeighbors(size_t vertex) {
    std::vector<int> neighbors;
    size_t size = adjMatrix.size();

    for (size_t i = 0; i < size; i++) {
        if (adjMatrix[vertex][i] != 0) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

// get the size of the graph
size_t Graph::getSize() {
    return adjMatrix.size();
}

/*
this function check if the graph has negative weight
*/
bool  Graph::isNegativeWeightedGraph(const Graph g){
    size_t size = g.adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (g.adjMatrix[i][j] < 0) { 
                return true;
            }
        }
    }
    return false;
}





} // namespace ariel

