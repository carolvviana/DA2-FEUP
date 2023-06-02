//
// Created by Sergio on 05/05/2023.
//

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
     * @brief algorithm
     * @param chosen_graph - graph to apply the Simulated Annealing algorithm
     * @param path - path to store the tour
     * @param initialTemperature - initial temperature
     * @param coolingRate - cooling rate
     * @param maxIterations - maximum number of iterations
     * @return cost of the tour
     * Time Complexity:
     */
    double nearestNeighboor(Graph& chosen_graph, std::vector<int> &path);
    double twoOpt(Graph& chosen_graph, std::vector<int> &path, double prevCost);
    std::vector<int> swapVertex(std::vector<int> &path, int i, int j);
    double getPathCost(Graph& chosen_graph, std::vector<int> &path);



private:


};


#endif //PROJETO_DA_2_TSP_H
