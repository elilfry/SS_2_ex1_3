/*
211691159
elifrydman08@gmail.com
*/

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
        if (graph.empty()) {
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
auto Graph::isWeightedGraph() -> bool{

    size_t size = adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if ( adjMatrix[i][j] != 1 && adjMatrix[i][j] != 0) { 

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
auto Graph::isDirectedGraph() -> bool{ 
    size_t size = adjMatrix.size();
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) { 
                return true;
            }
        }
    }
       

    return false;
}

auto Graph::getNumberOfEdges() -> size_t {
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
        return static_cast<size_t>(numEdges);
    }
    // undirected graph
        for (size_t i = 0; i < size; i++) {
            for (size_t j = i; j < size; j++) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                }
            }
        }
        return (size_t)numEdges;
   

}
auto Graph::getNeighbors(size_t vertex) -> std::vector<int> {
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
auto Graph::getSize() -> size_t {
    return adjMatrix.size();
}

/*
this function check if the graph has negative weight
*/
auto  Graph::isNegativeWeightedGraph() -> bool{
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

auto Graph::getWeight(size_t src, size_t dest) -> int {
    return  adjMatrix[src][dest];
}

auto Graph::getNumberOfVertices() -> size_t {
    return adjMatrix.size();
}

} // namespace ariel

