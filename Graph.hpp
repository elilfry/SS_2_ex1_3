#pragma once

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>


namespace ariel{
class Graph {
    private:
    std::vector<std::vector<int>> adjMatrix; 

    public:

//load graph
/*
the function load the graph to the object
*/

void loadGraph(const std::vector<std::vector<int>>& graph);

/*
the function return the neighbors of the vertex
@param vertex the vertex
@return the neighbors of the vertex
*/
std::vector<int> getNeighbors(size_t vertex) ;

size_t getSize() ;


/*

the function print the graph
*/
void printGraph();

size_t getNumberOfEdges();

size_t getNumberOfVertices();



bool isWeightedGraph();

bool isDirectedGraph();

bool isNegativeWeightedGraph();

int getWeight(size_t src, size_t dest);
 
};
}

#endif //GRAPH_HPP