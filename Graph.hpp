#pragma once

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>


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

std::vector<int> getNeighbors(size_t vertex) ;

size_t getSize() ;


/*

the function print the graph
*/
void printGraph();


bool isWeightedGraph(const Graph g);

bool isDirectedGraph(const Graph g);

bool isNegativeWeightedGraph(const Graph g);


 
};
}

#endif //GRAPH_HPP