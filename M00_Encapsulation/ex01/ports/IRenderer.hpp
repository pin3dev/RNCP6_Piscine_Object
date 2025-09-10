# pragma once
# include "../domain/Graph.hpp"

class Graph::IRenderer {
    public:
        virtual ~IRenderer() {}
        virtual void draw (const Graph& graph) const = 0;
};