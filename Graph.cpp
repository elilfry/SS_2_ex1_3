#include <iostream>
#include <vector>
#include "Graph.hpp"
using namespace std;

namespace ariel {

    



    void  Graph::loadGraph(const std::vector<std::vector<int>>& graph) {

        // Check if the graph is a square matrix.
        
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[i].size() != graph.size()) {
               throw invalid_argument(" Invalid_argument-The graph is not a square matrix.");
            }
        }

        // Check if the graph is empty.
        if (graph.size() == 0) {
            throw invalid_argument(" Invalid_argument-The graph is empty.");
        }

        // Check if the graph has a self loop
        for (size_t i = 0; i < graph.size(); i++) {
            if (graph[i][i] != 0) {
                throw invalid_argument(" Invalid_argument-The graph has a self loop.");
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
bool Graph::isWeightedGraph(){

    size_t size = adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if ( adjMatrix[i][j] != 1 && adjMatrix[i][j] != 0) { 
                  cout << "is Weighted Graph" << endl;

                return true;
            }
        }
    }
       cout << "is not WeightedG raph" << endl;

    return false;
}

/*
this function check if the graph is directed
if the graph is syimetric the graph is not directed -false
if the graph is  not syimetric the graph is directed - true
*/
bool Graph::isDirectedGraph(){ 
    size_t size = adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) { 
                    cout << "isDirectedGraph" << endl;
                return true;
            }
        }
    }
        cout << "is not Directed Graph" << endl;

    return false;
}

size_t Graph::getNumberOfEdges() {
    size_t size = adjMatrix.size();
    int numEdges = 0;
    
    if(isDirectedGraph()){ // if the graph is directed
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                }
            }
        }
        return numEdges;
    }
    else{ // undirected graph
        for (size_t i = 0; i < size; i++) {
            for (size_t j = i; j < size; j++) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                }
            }
        }
        return numEdges;
    }

}
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
bool  Graph::isNegativeWeightedGraph(){
    size_t size = adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (adjMatrix[i][j] < 0) { 
                return true;
            }
        }
    }
    return false;
}

//getWeight

int Graph::getWeight(size_t src, size_t dest) {
    return  adjMatrix[src][dest];
}

size_t Graph::getNumberOfVertices() {
    return adjMatrix.size();
}

} // namespace ariel

