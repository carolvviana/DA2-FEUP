// By: Gonçalo Leão

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
    int getDeletedSize() const;
    int getNotDeletedSize() const;
    std::set<Edge *> getAdjSet() const;
    std::vector<Vertex *> getAdjNodes() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Vertex* getPath() const;
    Vertex* getPerfectMatch() const;
    std::vector<Edge *> getIncoming() const;
    std::vector<Vertex *> getChildren() const;
    Coordinates getCoords() const;

    void setId(int info);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Vertex *path);
    void setPerfectMatch(Vertex *path);
    Edge * addEdge(Vertex *dest, double w);
    bool removeEdge(int destID);
    void setCoords(double lat, double lon);
    void setLabel(std::string label);
    void addChild(Vertex* v);
    void clearChildren();
    void removeChild(int i);
    void removeLastChild();


    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    std::vector<Edge *> adj;  // outgoing edges
    std::set<Edge*> adjSet;
    std::vector<Edge *> incoming; // incoming edges
protected:
    int id;                // identifier

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Vertex *path = nullptr;

    /**
     * @brief used in Prim's algorithm, stores all nodes connected to that node
     */
    std::vector<Vertex*> children;
    Vertex* perfect_match = nullptr;

    Coordinates coords;
    std::string label;



};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w);

    Vertex * getDest() const;
    double getWeight() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;
    bool getDeleted() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);
    void deleteEdge();

protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;
    bool deleted = false;

    double flow; // for flow-related problem
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */