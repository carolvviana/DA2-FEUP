#ifndef PROJETO_DA_2_TSP_H
#define PROJETO_DA_2_TSP_H


#include <string>
#include <unordered_set>
#include "Graph.h"

class TSP {
public:
    TSP();

    ~TSP();

    Graph graph;

    Graph mediumGraph;

    Graph toyGraphShipping;
    Graph toyGraphStadiums;
    Graph toyGraphTourism;

    /**
     * @brief creates Graph based on csv file - specific for toruism graph
     */
    void createTourism();

    /**
     * @brief creates Graph based on csv file
     * @param chosen_graph - graph to create
     * @param filePath - path to the chosen file
     * @param isSmall - true if it is a toyGraph and false otherwise
     */
    void createGraph(Graph& chosen_graph, const std::string& filePath, bool isSmall);

    /**
     * @brief creates Nodes of a graph based on csv file
     * @param chosen_graph - graph to create
     * @param filePath - path to the chosen file
     */
    void createNodes(Graph& chosen_graph, const std::string& filePath);

    /**
     * @brief creates Edges of a graph based on csv file
     * @param chosen_graph - graph to create
     * @param filePath - path to the chosen file
     */
    void createEdges(Graph& chosen_graph, const std::string& filePath);

    /**
     * @brief Auxiliary function for TSP using backtracking
     * @param graph - which graph to iterate over
     * @param n - number of Nodes
     * @param pos - which node we are currently visiting
     * @param visited - unordered set of nodes that have already been visited
     * @param cost - cost of the current path
     * @param minCost - minimum cost so far
     * @param curPath - current path
     * @param bestPath - minimum cost path so far
     * Time Complexity: O(V!)
     */
    void tspBTUtil(const Graph& graph, unsigned int n, unsigned int pos, std::unordered_set<int>& visited, double cost, double& minCost, std::vector<unsigned int>& curPath, std::vector<unsigned int>& bestPath);

    /**
     * @brief TSP using backtracking
     * @param graph - which graph to iterate over
     * @param n - number of Nodes
     * @param path - the path to follow will be stored here
     * @return cost of the tour
     * Time Complexity: O(V!)
     */
    double tspBT(const Graph& graph, unsigned int n, unsigned int* path);

    /**
     * @brief TSP approximation algorithm that relies on triangle inequality principal
     * @param graph - graph to apply the approximation
     * @param path - path to store the tour
     * @return cost of the tour
     * Time Complexity: O(V + E)
     */
    double tspTriangleHeuristic(Graph& graph, unsigned int* path);

    /**
     * @brief applies the Simulated Annealing algorithm to find the best tour
     * @param chosen_graph - graph to apply the Simulated Annealing algorithm
     * @param path - path to store the tour
     * @param initialTemperature - initial temperature
     * @param coolingRate - cooling rate
     * @param maxIterations - maximum number of iterations
     * @return cost of the tour
     * Time Complexity:
     */
    double simulatedAnnealing(Graph& chosen_graph, std::vector<int>& path, double initialTemperature = 1000.0,
                               double coolingRate = 0.995, int maxIterations = 100);

    /**
     * @brief Nearest neighboor algorithm - constructs path by finding the nearest node that hasn't yet been visited
     * @param chosen_graph - graph to apply the algorithm
     * @param path - path to store the tour
     * @return cost of the tour
     * Time Complexity: O(V + E)
     */
    double nearestNeighboor(Graph& chosen_graph, std::vector<int> &path);

    /**
     * @brief 2-opt optimization algorithm - is given a path and optimizes it by switching to edges at a time (if it results in smaller cost)
     * @param chosen_graph - graph to apply the algorithm
     * @param path - path to store the tour
     * @param prevCost - initial cost of the path (before the optimization)
     * @return cost of the tour
     * Time Complexity: O(V^2)
     */
    double twoOpt(Graph& chosen_graph, std::vector<int> &path, double prevCost);

    /**
     * @brief swaps two nodes in a path
     * @param path - path where the nodes are being swapped
     * @param i - index to swap
     * @param j - index to swap
     * @return path with elements swapped
     * Time Complexity: O(1)
     */
    std::vector<int> swapVertex(std::vector<int> &path, int i, int j);

    /**
     * @brief calculates the total cost of a given path
     * @param chosen_graph - graph where the path belongs
     * @param path - path (of nodes' ids) that we want to know the cost of
     * @return cost of path
     * Time Complexity: O(n)
     */
    double getPathCost(Graph& chosen_graph, std::vector<int> &path);

    /**
     * @brief calculates the total cost of a given path
     * @param chosen_graph - graph where the path belongs
     * @param path - path (of nodes themselves) that we want to know the cost of
     * @return cost of path
     * Time Complexity: O(n)
     */
    double getPathCost(Graph& chosen_graph, std::vector<Vertex*> &path);

    /**
     * @brief christofides algorithm - combines MST and a minimum-weight perfect matching tree
     * @param chosen_graph - graph to apply the algorithm
     * @param path - where to store the final path
     * @return cost of path
     * Time Complexity: O(V^3)
     */
    double christofides(Graph& chosen_graph, std::vector<Vertex*> &path);



private:


};


#endif //PROJETO_DA_2_TSP_H
