//
// Created by Sergio on 05/05/2023.
//

#ifndef PROJETO_DA_2_TSP_H
#define PROJETO_DA_2_TSP_H


#include <string>
#include "Graph.h"

class TSP {
public:
    TSP(
            );

    Graph graph;

    Graph toyGraphShipping;
    Graph toyGraphStadiums;
    Graph toyGraphTourism;

    void createShipping();
    void createStadiums();
    void createTourism();

    void createNodes(const std::string& filePath);
    void createEdges(const std::string& filePath);

private:


};


#endif //PROJETO_DA_2_TSP_H
