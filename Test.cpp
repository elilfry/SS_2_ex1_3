/*
211691159
elifrydman08@gmail.com
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);


}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "The shortest path from 0 to 2 is: 0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "No path exists between the source and destination vertices");

     vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 5) == "Negative cycle exists in the graph");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph does not contain a cycle");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");

    vector<vector<int>> graph3 = { // Directed graph with negative cycle
        {0, 0, 1},
        {-5, 0, 0},
        {0, 2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->1->0");

    

    vector<vector<int>> graph4 = { // Directed graph with a cycle
        {0, 0, 0},
        {0, 0, -20},
        {0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 1->2->1");

    

    vector<vector<int>> graph5 = { // Directed graph without a cycle
        {0, 0, -1},
        {0, 0, 2},
        {0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph does not contain a cycle");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");


    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph1));

    vector<vector<int>> graph2 = {
        {0, 1, 2, 0},
        {1, 2, 3, 0},
        {2, 3, 1, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph2));


    
}

TEST_CASE("Test empty graph") {
    ariel::Graph g;
    // No need to load any graph here, it's empty by default
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "The graph is empty");  // Empty graph has no path
    CHECK(ariel::Algorithms::isConnected(g) == false);  // Empty graph is not connected
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph does not contain a cycle");  // Empty graph has no cycles
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={}, B={}");  // Empty graph is bipartite
}

TEST_CASE("Test shortestPath for longer path") {
  ariel::Graph g;
  vector<vector<int>> graph = {
      {0, 1, 0, 0, 0},
      {1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0},
      {0, 1, 1, 0, 1},
      {0, 0, 0, 1, 0}};
  g.loadGraph(graph);
  CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "The shortest path from 0 to 4 is: 0->1->3->4");
}

TEST_CASE("Test negativeCycle") {
     ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK( ariel::Algorithms::negativeCycle(g) == "No negative cycle.");

    vector<vector<int>> graph2 = {// negative edges but cycle is not negative
                                  {0, 1, -3, 0, 0},
                                  {0, 0, 0, 2, 0},
                                  {0, 0, 0, 0, 3},
                                  {0, -1, 0, 0, 0},
                                  {0, 0, 0, -2, 0}};
    g.loadGraph(graph2);
    CHECK( ariel::Algorithms::negativeCycle(g) == "No negative cycle.");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -1, 0, 0, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK( ariel::Algorithms::negativeCycle(g) == "Negative cycle exists in the graph");

    
}

