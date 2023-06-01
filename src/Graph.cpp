// By: Gonçalo Leão

#include <cmath>
#include "Graph.h"
#include "MutablePriorityQueue.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const int &id, double lat, double lon) {
    if (findVertex(id) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(id, lat, lon));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c; //in km
}

void Graph::minCostMST() {
    std::vector<Vertex*> res;
    if (vertexSet.empty()) {
        return;
    }
    // Reset auxiliary info
    for(auto v : vertexSet) {
        v->setDist(INF);
        v->setPath(nullptr);
        v->setVisited(false);
    }
    // start with an arbitrary vertex
    Vertex* s = vertexSet.front();
    s->setDist(0);

    // initialize priority queue
    MutablePriorityQueue<Vertex> q;
    q.insert(s);

    // process vertices in the priority queue
    while(!q.empty() ) {
        double weight = 0;
        auto v = q.extractMin();

        v->setVisited(true);

        for(auto &w : vertexSet) { // vai iterar por todos os vértices porque também temos de considerar aqueles que não têm uma edge
            if (!w->isVisited()) { //para todos os vértices que ainda não foram visitados

                for (auto e: v->getAdj()){
                    if (e->getDest() == w){
                        weight = e->getWeight(); // se ele existir vai ser esse o peso
                        break;
                    }
                }
                if (weight == 0) weight = calculateDistance(v->getCoords().lat, v->getCoords().lon, w->getCoords().lat, w->getCoords().lon);
                // se não existir é a distância

                double oldDist = w->getDist();
                if(weight < oldDist) {
                    w->setDist(weight);
                    w->setPath(v);
                    //v->addChild(w);
                    if (oldDist == INF) {
                        q.insert(w);
                    }
                    else {
                        q.decreaseKey(w);
                    }
                }
            }
        }
    }
    for (auto v: vertexSet){
        auto w = v->getPath();
        if (w==nullptr) continue;
        w->addChild(v);
    }
}

void Graph :: preOrderVisit(Vertex* v, std::vector<Vertex*> &visitedNodes) {
    if (v == nullptr) {
        return;
    }

    visitedNodes.push_back(v);

/*
    //visit in preorder
    cost += v->getDist();
    std::cout << v->getDist() << '\n';
    std::cout << cost << '\n';
    */

    for (auto w: vertexSet) {
        if (w->getPath() == v) {
            preOrderVisit(w, visitedNodes);
        }
    }
}

double Graph :: getWeight(Vertex* v, Vertex* w){
    double weight = 0;
    for (auto e: v->getAdj()){
        if (e->getDest()->getId() == w->getId()){
            weight = e->getWeight();
        }
    }
    return weight;
}

std::vector<Vertex*> Graph::findOddDegree() {
    std::vector<Vertex*> odd;
    for (auto v: vertexSet) {
        // if degree of vertex v is odd
        if ((v->getChildren().size() % 2) != 0) {
            odd.push_back(v);
        }
    }
    return odd;
}

void Graph::perfectMatching() { //minCostPerfectMatching -> greedy version
    double length;
    std::vector<Vertex*>::iterator tmp;
    std::vector<Vertex*> odds;
    Vertex* closest_vertex;

    odds = findOddDegree();

    // for each odd node
    while (!odds.empty()) {
        Vertex* first_vertex = odds[0];
        length = std::numeric_limits<double>::max();
        for (auto it = odds.begin()+1; it != odds.end(); ++it) {
            if (getWeight(first_vertex, *it) < length) {
                length = getWeight(first_vertex, *it);
                closest_vertex = *it;
                tmp = it;
            }
        }

        first_vertex->addChild(closest_vertex);
        closest_vertex->addChild(first_vertex);
        //first_vertex->setPerfectMatch(closest_vertex);
        //closest_vertex->setPerfectMatch(first_vertex);
        odds.erase(tmp);
        odds.erase(odds.cbegin());
    }
}

//find an euler circuit
void Graph::eulerTour(int start, std:: vector<Vertex*> &path){
    int deleted = 0;
    std::stack<int> stack;
    int pos = start;
    path.push_back(vertexSet[start]);
    while(!stack.empty() || !vertexSet[pos]->getChildren().empty() ){
        //Current node has no neighbors
        if (vertexSet[pos]->getChildren().empty()){
            //add to circuit
            path.push_back(vertexSet[pos]);
            //remove last vertex from stack and set it to current
            pos = stack.top();
            stack.pop();
        }
            //If current node has neighbors
        else{
            //Add vertex to stack
            stack.push(pos);
            //Take a neighbor
            int neighbor = vertexSet[pos]->getChildren().back()->getId(); // este é um id, nao uma posição
            //Remove edge between neighbor and current vertex
            vertexSet[pos]->removeLastChild();
            //deleted++;

            for(int i = 0; i < findVertex(neighbor)->getChildren().size(); i++){
                if(findVertex(neighbor)->getChildren()[i] == findVertex(pos)){
                    findVertex(neighbor)->removeChild(i);
                }
            }
            //Set neighbor as current vertex
            pos = findVertexIdx(neighbor);
        }
    }
    path.push_back(vertexSet[pos]);
}

//Make euler tour Hamiltonian
void Graph::makeHamiltonian(std::vector<Vertex*> &path, double &pathCost){

    //remove visited nodes from Euler tour
    for(auto v: vertexSet){
        v->setVisited(false);
    }

    pathCost = 0;

    Vertex* root = path.front();
    auto cur = path.begin();
    auto iter = path.begin()+1;
    root->setVisited(true);

    //iterate through circuit
    bool addMore = true;
    while(iter != path.end()){
        if(!((*iter)->isVisited())){
            pathCost += getWeight(*cur, *iter);
            cur = iter;
            (*cur)->setVisited(true);
            iter = cur++;
        }
        else{
            iter = path.erase(iter);
        }
    }
    //Add distance to root
    if ( iter != path.end() ){
        pathCost += getWeight(*cur, *iter);
    }
}

double Graph::findBestPath(int start){
    std:: vector<Vertex*> path;
    eulerTour(start, path);
    double length;

    makeHamiltonian(path, length);
    return length;
}

