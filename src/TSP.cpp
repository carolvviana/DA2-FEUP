//
// Created by Sergio on 05/05/2023.
//

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
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
    double minCost = 0.0;
    chosen_graph.preOrderVisit(chosen_graph.findVertex(0), minPath, true, minCost);
    for (unsigned int i = 0; i < minPath.size(); i++) {
        path[i] = minPath[i]->getId();
    }

    //distance from last to first
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

double TSP :: nearestNeighboor(Graph& chosen_graph, std::vector<int> &path){
    unordered_set<int> not_visited;
    double cost = 0;


    for (auto v: chosen_graph.getVertexSet()){
        v->setVisited(false);
        not_visited.insert(v->getId());
    }

    int current_stop = 0;
    int last_stop = 0;
    path.push_back(0);
    chosen_graph.findVertex(0)->setVisited(true);
    not_visited.erase(0);

    while (!not_visited.empty()){
        bool found = false;
        int next_stop;
        double min_distance = std::numeric_limits<double>::max();
        for (auto e: chosen_graph.findVertex(current_stop)->getAdj()){
            if (!e->getDest()->isVisited() && e->getWeight() < min_distance){
                next_stop= e->getDest()->getId();
                min_distance = e->getWeight();
                found = true;
            }
        }

        if (found){
            cost += min_distance;
            std::cout << min_distance << "  :  " << cost << endl;
            chosen_graph.findVertex(next_stop)->setVisited(true);
            path.push_back(next_stop);
            not_visited.erase(current_stop);
            last_stop = current_stop;
            current_stop = next_stop;
        }
        else break;
    }
    path.push_back(0);

    for (auto e: chosen_graph.findVertex(current_stop)->getAdj()){
        if (e->getDest()->getId() == 0){
            cost+=e->getWeight();
        }
    }
    return cost;
}

double TSP :: twoOpt(Graph& chosen_graph, std::vector<int> &path, double prevCost){
    std::vector<int> new_path;
    double newCost;
    double bestCost = prevCost;
    int swaps = 1;

    while (swaps != 0) { //until no improvements are being made.
        swaps = 0;
        for (int i = 1; i <= path.size() - 3 ; i++) {
            for (int j = i+1; j <= path.size() - 2; j++ ){
                if (   (chosen_graph.getWeight(chosen_graph.findVertex(path[i]),chosen_graph.findVertex(path[i-1])))     +   (chosen_graph.getWeight(chosen_graph.findVertex(path[j+1]),chosen_graph.findVertex(path[j])))
                                                >=     (chosen_graph.getWeight(chosen_graph.findVertex(path[i]),chosen_graph.findVertex(path[j+1])))    +(chosen_graph.getWeight(chosen_graph.findVertex(path[i-1]),chosen_graph.findVertex(path[j])))){
                    new_path = swapVertex(path, i, j);
                    newCost = getPathCost(chosen_graph,new_path);
                    if (newCost < bestCost) {
                        path = new_path;
                        bestCost = newCost;
                        swaps++;
                    }
                }
            }
        }
    }
    return bestCost;
}

std::vector<int> TSP:: swapVertex(std::vector<int> &path, int i, int j){
    std::vector<int> sol;
    for (int c = 0; c <= i - 1; c++) {
        sol.push_back(path[c]);
    }
    int count = 0;
    for (int c = i; c <= j; c++) {
        sol.push_back(path[j - count]);
        count++;
    }
    for (int c = j + 1; c < path.size(); c++) {
        sol.push_back(path[c]);
    }
    return sol;
}

double TSP:: getPathCost(Graph& chosen_graph, std::vector<int> &path){
    double cost = 0;
    for (int i = 0; i < path.size()-1; i++){
        cost += chosen_graph.getWeight(chosen_graph.findVertex(path[i]), chosen_graph.findVertex(path[i+1]));
    }
    return cost;
}

double TSP::getPathCost(Graph& chosen_graph, std::vector<Vertex*> &path){
    double cost = 0;
    for (int i = 0; i < path.size()-1; i++){
        cost += chosen_graph.getWeight(path[i], path[i+1]);
    }
    return cost;
}

double TSP :: christofides(Graph& chosen_graph, std::vector<Vertex*> &path){
    chosen_graph.minCostMST();

    chosen_graph.perfectMatching();

    // Loop through each index and find shortest path
    /*double best = std::numeric_limits<double>::max();
    int bestIndex;
    for (long t = 0; t < chosen_graph.getNumVertex(); t++) {
        double result = chosen_graph.findBestPath(t);

       /* tsp.path_vals[t][0] = t; // set start
        tsp.path_vals[t][1] = result; // set end*/

   /*     if (result < best) {
            bestIndex = t;
            best = result;
        }
    }*/

    chosen_graph.eulerTour(0,path);
    double min_cost = getPathCost(chosen_graph, path);
    //chosen_graph.makeHamiltonian(path, min_cost);

    return min_cost;
}