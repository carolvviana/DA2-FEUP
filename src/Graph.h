// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_set>
//#include "../data_structures/MutablePriorityQueue.h"

#include "VertexEdge.h"

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const int &id, double lat, double lon);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const int &sourc, const int &dest, double w);
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;

    double getWeight(Vertex* v, Vertex* w);

    void clearGraph();

    void minCostMST();

    void preOrderVisit(Vertex* v, std::vector<Vertex*> &visitedNodes);

protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

/**
 * Function that returns the distance between two points with coordinates passed by parameter
 * Time Complexity: O(log(n))
 * @param lat1 - a double value represents the latitude of first point
 * @param lon1 - a double value represents the longitude of first point
 * @param lat2 - a double value represents the latitude of second point
 * @param lon2 - a double value represents the longitude of second point
 * @return - a double value containing the distance between two points
 */
double calculateDistance(double lat1, double lon1, double lat2, double lon2);

#endif /* DA_TP_CLASSES_GRAPH */