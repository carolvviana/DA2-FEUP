//
// Created by Sergio on 05/05/2023.
//

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <chrono>
#include <random>
#include "TSP.h"

using namespace std;

TSP::TSP() {
    createShipping(); createStadiums(); createTourism();
}

void TSP::createNodes(const std::string &filePath) {
    ifstream file;
    file.open(filePath);
    string line;

    /* Check if file is open */
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    /* Read the first line (labels) */
    getline(file,line);

    if(line != "id,longitude,latitude"){
        cout << "Error reading file, wrong format of file" << endl;
        return;
    }

    /* Read the rest of the file */
    while(getline(file, line)){
        istringstream iss(line);

        /* Labels */
        string id, lat, lon;
        list<string* > labels = {&id, &lat, &lon};

        for(string* label : labels) {
            std::string labelData;

            std::getline(iss, labelData, ',');

            *label = labelData;
        }

        graph.addVertex(stoi(id), stod(lat), stod(lon));
    }
}

void TSP::createEdges(const string &filePath) {
    ifstream file;
    file.open(filePath);
    string line;

    /* Check if file is open */
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    /* Read the first line (labels) */
    getline(file,line);

    if(line != "origem,destino,distancia"){
        cout << "Error reading file, wrong format of file" << endl;
        return;
    }

    /* Read the rest of the file */
    while(getline(file, line)){
        istringstream iss(line);

        /* Labels */
        string origin, dest, dist;
        list<string* > labels = {&origin, &dest, &dist};

        for(string* label : labels) {
            std::string labelData;

            std::getline(iss, labelData, ',');

            *label = labelData;
        }

        graph.addBidirectionalEdge(stoi(origin), stoi(dest), stod(dist));
    }
}

void TSP::createShipping() {
    ifstream file;
    file.open("../data/Toy-Graphs/shipping.csv");
    string line;

    /* Check if file is open */
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    /* Read the first line (labels) */
    getline(file,line);

    if(line != "origem,destino,distancia"){
        cout << "Error reading file, wrong format of file" << endl;
        return;
    }

    /* Read the rest of the file */
    while(getline(file, line)){
        istringstream iss(line);

        /* Labels */
        string origin, dest, dist;
        list<string* > labels = {&origin, &dest, &dist};

        for(string* label : labels) {
            std::string labelData;

            std::getline(iss, labelData, ',');

            *label = labelData;
        }
        toyGraphShipping.addVertex(stoi(origin), 0,0);
        toyGraphShipping.addVertex(stoi(dest), 0,0);
        toyGraphShipping.addBidirectionalEdge(stoi(origin), stoi(dest), stod(dist));
    }

}

void TSP::createStadiums() {
    ifstream file;
    file.open("../data/Toy-Graphs/stadiums.csv");
    string line;

    /* Check if file is open */
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    /* Read the first line (labels) */
    getline(file,line);

    if(line != "origem,destino,distancia"){
        cout << "Error reading file, wrong format of file" << endl;
        return;
    }

    /* Read the rest of the file */
    while(getline(file, line)){
        istringstream iss(line);

        /* Labels */
        string origin, dest, dist;
        list<string* > labels = {&origin, &dest, &dist};

        for(string* label : labels) {
            std::string labelData;

            std::getline(iss, labelData, ',');

            *label = labelData;
        }
        toyGraphStadiums.addVertex(stoi(origin), 0,0);
        toyGraphStadiums.addVertex(stoi(dest), 0,0);
        toyGraphStadiums.addBidirectionalEdge(stoi(origin), stoi(dest), stod(dist));
    }
}

void TSP::createTourism() {
    ifstream file;
    file.open("../data/Toy-Graphs/tourism.csv");
    string line;

    /* Check if file is open */
    if(!file.is_open()){
        cout << "Error opening file" << endl;
        return;
    }

    /* Read the first line (labels) */
    getline(file,line);

    if(line != "origem,destino,distancia,label origem,label destino"){
        cout << "Error reading file, wrong format of file" << endl;
        return;
    }

    /* Read the rest of the file */
    while(getline(file, line)){
        istringstream iss(line);

        /* Labels */
        string origin, dest, dist, labelOrigin, labelDest;
        list<string* > labels = {&origin, &dest, &dist, &labelOrigin, &labelDest};

        for(string* label : labels) {
            std::string labelData;

            std::getline(iss, labelData, ',');

            *label = labelData;
        }
        toyGraphTourism.addVertex(stoi(origin), 0,0);
        toyGraphTourism.findVertex(stoi(origin))->setLabel(labelOrigin);
        toyGraphTourism.addVertex(stoi(dest), 0,0);
        toyGraphTourism.findVertex(stoi(dest))->setLabel(labelDest);
        toyGraphTourism.addBidirectionalEdge(stoi(origin), stoi(dest), stod(dist));
    }
}

void TSP::tspBTUtil(const Graph& graph, unsigned int n, unsigned int pos, std::unordered_set<int>& visited, double cost, double& minCost, std::vector<unsigned int>& curPath, std::vector<unsigned int>& bestPath) {
    visited.insert(pos);
    curPath.push_back(pos);

    bool canBack = false;
    int temp_weight = 0;
    /*if (visited.size() == n){
        for (auto e: vertexSet[pos]->getAdj()){
            if (e->getDest()->getId() == 0) canBack = true;
        }
    }*/

    if (visited.size() == n) {
        for (auto e: graph.findVertex(pos)->getAdj()){
            if (e->getDest()->getId() == 0) { canBack = true; temp_weight = e->getWeight(); break; }
        }
        if (canBack){
            cost += temp_weight;
            if ((cost < minCost)) {
                minCost = cost;
                bestPath = curPath;
            }
            curPath.pop_back();
            visited.erase(pos);
            return;
        }
    }

    for (const Edge* e : graph.findVertex(pos)->getAdj()) {
        if (visited.find(e->getDest()->getId()) == visited.end()) {
            double newCost = cost + e->getWeight();
            if (newCost < minCost) {
                tspBTUtil(graph, n, e->getDest()->getId(), visited, newCost, minCost, curPath, bestPath);
            }
        }
    }
    curPath.pop_back();
    visited.erase(pos);
}

double TSP::tspBT(const Graph& graph, unsigned int n, unsigned int* path) {
    std::unordered_set<int> visited;
    double minCost = std::numeric_limits<double>::max();
    std::vector<unsigned int> curPath;
    std::vector<unsigned int> bestPath;

    //std::vector<Vertex *> vertexSet = graph.getVertexSet();
    tspBTUtil(graph, n, 0, visited, 0, minCost, curPath, bestPath);
    //tspBTUtil2(vertexSet, n, 0, 0, minCost, curPath, bestPath);

    for (unsigned int i = 0; i < n; i++) {
        path[i] = bestPath[i];
    }

    return minCost;
}

double TSP::tspTriangleHeuristic(Graph& chosen_graph, unsigned int* path) {
    vector<Vertex*> minPath;
    chosen_graph.minCostMST();
    chosen_graph.preOrderVisit(chosen_graph.findVertex(0), minPath);

    double minCost = 0.0;

    Vertex * previousVertex = minPath[0];
    path[0] = minPath[0]->getId();
    for(unsigned int i = 1; i< minPath.size(); i++){
        for(Edge* e : minPath[i]->getAdj()) {
            if (e->getDest() == previousVertex) {
                minCost += e->getWeight();
            } else {
                minCost += calculateDistance(previousVertex->getCoords().lat, previousVertex->getCoords().lon,
                                             minPath[i]->getCoords().lat, minPath[i]->getCoords().lon);
            }
        }
        previousVertex = minPath[i];
        path[i] = minPath[i]->getId();
    }

    //distance from last to first vertex
    Vertex* lastVertex = minPath.back();
    Vertex* firstVertex = chosen_graph.findVertex(0);

    bool foundEdge = false;
    for(Edge* e : lastVertex->getAdj()){
        if(e->getDest() == firstVertex){
            minCost += e->getWeight();
            foundEdge = true;
        }
    }

    if(!foundEdge){
        minCost += calculateDistance(lastVertex->getCoords().lat, lastVertex->getCoords().lon, firstVertex->getCoords().lat, firstVertex->getCoords().lon);
    }

    return minCost;
}

double TSP::simulatedAnnealing(Graph& chosen_graph, unsigned int* path, double initialTemperature,
                                double coolingRate, int maxIterations){

    unsigned int currentPath[chosen_graph.getVertexSet().size()];
    randomTour(chosen_graph, currentPath);

    double currentCost = calculatePathCost(chosen_graph, currentPath);

    unsigned int bestPath[chosen_graph.getVertexSet().size()];
    bestPath = currentPath;


}

double TSP::calculatePathCost(Graph& graph, unsigned int* path){
    double cost = 0.0;

    for(unsigned int i = 0; i < graph.getVertexSet().size()-1; i++){
        Vertex* v1 = graph.findVertex(path[i]);
        Vertex* v2 = graph.findVertex(path[i+1]);

        bool foundEdge = false;
        for(Edge* e : v1->getAdj()){
            if(e->getDest() == v2){
                cost += e->getWeight();
                foundEdge = true;
                break;
            }
        }

        if(!foundEdge){
            cost += calculateDistance(v1->getCoords().lat, v1->getCoords().lon, v2->getCoords().lat, v2->getCoords().lon);
        }
    }

    //distance from last to first vertex
    Vertex* lastVertex = graph.findVertex(path[graph.getVertexSet().size()-1]);
    Vertex* firstVertex = graph.findVertex(path[0]);

    bool foundEdge = false;
    for(Edge* e : lastVertex->getAdj()){
        if(e->getDest() == firstVertex){
            cost += e->getWeight();
            foundEdge = true;
            break;
        }
    }

    if(!foundEdge){
        cost += calculateDistance(lastVertex->getCoords().lat, lastVertex->getCoords().lon, firstVertex->getCoords().lat, firstVertex->getCoords().lon);
    }

    return cost;
}

void TSP::randomTour(Graph& graph, unsigned int* path){
    // obtain a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    minstd_rand0 generator (seed);

    //shuffle the path keeping the first index as 0
    path[0] = 0;
    shuffle(path+1, path+graph.getVertexSet().size(), generator);
}



