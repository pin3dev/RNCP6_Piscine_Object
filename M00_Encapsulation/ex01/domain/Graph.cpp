# include "Graph.hpp"

Graph::Graph(Vector2 size) : _size(size) {}
Graph::~Graph() {}

void Graph::addPoint(const Vector2& point) {
    if (point.x < 0 || point.x > _size.x || point.y < 0 || point.y > _size.y) {
        throw std::out_of_range("Point is out of graph bounds");
    }
    _points.push_back(point);
}