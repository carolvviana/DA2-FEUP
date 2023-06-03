#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits>
#include <algorithm>

class Edge;

#define INF std::numeric_limits<double>::max()

struct Coordinates{
    double lat;
    double lon;
};

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex(int id, double lat, double lon);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    int getId() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    double getDist() const;
    Vertex* getPath() const;
    std::vector<Vertex *> getChildren() const;
    Coordinates getCoords() const;

    void setVisited(bool visited);
    void setDist(double dist);
    void setPath(Vertex *path);
    Edge * addEdge(Vertex *dest, double w);
    void setLabel(std::string label);
    void addChild(Vertex* v);
    void clearChildren();

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    std::vector<Edge *> adj;  // outgoing edges
    std::set<Edge*> adjSet;
    std::vector<Edge *> incoming; // incoming edges
protected:
    int id;                // identifier

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    double dist = 0;
    Vertex *path = nullptr;

    /**
     * @brief used in Prim's algorithm, stores all nodes connected to that node
     */
    std::vector<Vertex*> children;

    Coordinates coords;
    std::string label;
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w);

    Vertex * getDest() const;
    double getWeight() const;
    Vertex * getOrig() const;

    void setReverse(Edge *reverse);

protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity

    // used for bidirectional edges
    Vertex *orig;
    bool deleted = false;
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */