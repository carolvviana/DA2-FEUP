#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <stack>

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

    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);

    int getNumVertex() const;

    std::vector<Vertex *> getVertexSet() const;

    /**
     * @brief return the weight of the edge that connects two vertexes
     * @param v - vertex 1
     * @param w - vertex 2
     * @return - weight of the edge that connects both vertexes
     */
    double getWeight(Vertex* v, Vertex* w);

    /**
     * @brief deletes a certain graph
     */
    void clearGraph();

    /**
     * @brief computes a minimum cost spanning tree using prim's algorithm
     * Time complexity: O ( (V + E) log(V) )
     * @return - set of edges that form the tree
     */
    std::set<Edge*>  minCostMST();

    /**
     * @brief computes a preorder visit of a certain tree
     * @param v starting node
     * @param visitedNodes vector of node s that have been visited by the preorder
     * Time complexity: O (V + E)
     */
    void preOrderVisit(Vertex* v, std::vector<Vertex*> &visitedNodes);

    /**
     * @brief finds all nodes with odd degree
     * @param v starting node
     * @param visitedNodes vector of node s that have been visited by the preorder
     * Time complexity: O (V)
     */
    std::vector<Vertex*> findOddDegree();

    /**
     * @brief finds a minimum weight, perfect matching tree
     * @param vertices vector of vertices where you want to get the MWPM
     * Time complexity: O (V*E)
     */
    std::set<Edge*> perfectMatching(const std::vector<Vertex*>& vertices);


protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall
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