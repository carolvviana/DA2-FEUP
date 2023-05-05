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


