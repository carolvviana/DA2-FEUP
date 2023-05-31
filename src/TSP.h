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

    Graph graph;

    Graph toyGraphShipping;
    Graph toyGraphStadiums;
    Graph toyGraphTourism;

    void createShipping();
    void createStadiums();
    void createTourism();

    void createNodes(const std::string& filePath);
    void createEdges(const std::string& filePath);

    void tspBTUtil(const Graph& graph, unsigned int n, unsigned int pos, std::unordered_set<int>& visited, double cost, double& minCost, std::vector<unsigned int>& curPath, std::vector<unsigned int>& bestPath);

    double tspBT(const Graph& graph, unsigned int n, unsigned int* path);

    double tspTriangleHeuristic(Graph& graph, unsigned int* path);

    /**
     * @brief applies the Simulated Annealing algorithm to find the best tour
     * @param chosen_graph - graph to apply the Simulated Annealing algorithm
     * @param path - path to store the tour
     * @param initialTemperature - initial temperature
     * @param coolingRate - cooling rate
     * @param maxIterations - maximum number of iterations
     * @return cost of the tour
     */
    double simulatedAnnealing(Graph& chosen_graph, std::vector<int>& path, double initialTemperature = 1000.0,
                               double coolingRate = 0.995, int maxIterations = 100);

    double nearestNeighboor(Graph& chosen_graph, std::vector<int> &path);
    double twoOpt(Graph& chosen_graph, std::vector<int> &path, double prevCost);
    std::vector<int> swapVertex(std::vector<int> &path, int i, int j);
    double getPathCost(Graph& chosen_graph, std::vector<int> &path);



    /**
     * @brief generates a random tour starting and ending at node 0
     * @param graph - graph to generate the tour
     * @param path - path to store the tour
     */
    static void randomTour(Graph& graph, std::vector<int>& path);

    /**
     * @brief calculates the cost of a tour
     * @param graph - graph to calculate the cost
     * @param path - path to calculate the cost
     * @return - cost of the tour
     */
    static double calculatePathCost(Graph& graph, unsigned int* path);
private:


};


#endif //PROJETO_DA_2_TSP_H
