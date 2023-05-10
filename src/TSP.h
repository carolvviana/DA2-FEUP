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

    void tspBTUtil(const std::vector<Vertex *>& vertexSet, unsigned int n, unsigned int pos, std::unordered_set<int>& visited, double cost, double& minCost, std::vector<unsigned int>& curPath, std::vector<unsigned int>& bestPath);

    double tspBT(const Graph& graph, unsigned int n, unsigned int* path);

private:


};


#endif //PROJETO_DA_2_TSP_H
