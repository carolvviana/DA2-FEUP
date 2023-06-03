// By: Gonçalo Leão

#include "VertexEdge.h"

/************************* Vertex  **************************/

Vertex::Vertex(int id, double lat, double lon): id(id) {
    this->coords.lat = lat;
    this->coords.lon = lon;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge * Vertex::addEdge(Vertex *d, double w) {
    auto newEdge = new Edge(this, d, w);
    adj.push_back(newEdge);
    adjSet.insert(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

void Vertex::addChild(Vertex* v){
    children.push_back(v);
}

void Vertex::clearChildren(){
    children.clear();
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

int Vertex::getId() const {
    return this->id;
}

std::vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

std::vector<Vertex *> Vertex::getChildren() const{
    return this->children;
}

bool Vertex::isVisited() const {
    return this->visited;
}

double Vertex::getDist() const {
    return this->dist;
}

Vertex* Vertex::getPath() const {
    return this->path;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Vertex *path) {
    this->path = path;
}

Coordinates Vertex::getCoords() const {
    return coords;
}

void Vertex::setLabel(std::string label) {
    this->label = label;
}

/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, double w): orig(orig), dest(dest), weight(w) {}

Vertex * Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

